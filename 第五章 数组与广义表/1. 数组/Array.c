//
//  Array.c
//  DataStructure
//
//  Created by hao on 2024/7/4.
//

#include "Array.h"
#include <malloc/_malloc.h>
#include <stdlib.h>

//----- 基本操作的算法描述 -----

Status InitArray(Array *A, int dim, ...) {
    // 若维数 dim 和各维长度合法，则构造相应的数组 A，并返回 OK
    if (dim < 1 || dim > MAX_ARRAY_DIM) return ERROR;
    A->dim = dim;
    A->bounds = (int *)malloc(dim * sizeof(int));
    if (!A->bounds) exit(OVERFLOW);
    // 若各维长度合法，则存入 A.bounds，并求出 A 的元素总数 elemtotal
    int elemtotal = 1;
    va_list ap;
    va_start(ap, dim);
    for (int i=0; i<dim; i++) {
        A->bounds[i] = va_arg(ap, int);
        if (A->bounds[i] < 0) {
            va_end(ap);
            return UNDERFLOW;
        }
        elemtotal *= A->bounds[i];
    }
    va_end(ap);
    A->base = (ElemType *)malloc(elemtotal * sizeof(ElemType));
    if (!A->base) exit(OVERFLOW);
    // 求映像函数的常量 ci，并存入 A.constants[i-1],i = 1,...,dim
    A->constants = (int *)malloc(dim * sizeof(int));
    if (!A->constants) exit(OVERFLOW);
    // L = 1，指针的增减以元素的大小为单位
    A->constants[dim - 1] = 1;
    for (int i=dim-2; i>=0; --i)
        A->constants[i] = A->bounds[i+1] * A->constants[i+1];
    return OK;
}

/// 销毁数组 A
Status DestroyArray(Array *A) {
    if (!A->base) return ERROR;
    free(A->base);
    A->base = NULL;
    if (!A->bounds) return ERROR;
    free(A->bounds);
    A->bounds = NULL;
    if (!A->constants) return ERROR;
    free(A->constants);
    A->constants = NULL;
    return OK;
}

/// 若 ap 指示的各下标值合法，则求出该元素在 A 中相对地址 off
Status Locate(Array A, va_list ap, int *off) {
    off = 0;
    for (int i=0; i<A.dim; ++i) {
        int ind = va_arg(ap, int);
        if (ind < 0 || ind >= A.bounds[i]) return OVERFLOW;
        off += A.constants[i] * ind;
    }
    return OK;
}

/// A 是 n 维数组，e为元素变量，随后是 n 个下标值。
/// 若各下标不超界，则 e 赋值为所指定的 A 的元素，并返回 OK
Status Value(Array A, ElemType *e, ...) {
    va_list ap;
    va_start(ap, e);
    Status result;
    int off = 0;
    if ((result = Locate(A, ap, &off)) <= 0) {
        va_end(ap);
        return result;
    }
    va_end(ap);
    *e = *(A.base + off);
    return OK;
}

/// A 是 n 维数组，e 为元素变量，随后是 n 个下标值。
/// 若下标不超界，则将 e 的值赋值给指定的 A 的元素，并返回 OK
Status Assign(Array *A, ElemType e, ...) {
    va_list ap;
    va_start(ap, e);
    int off = 0;
    Status result;
    if ((result = Locate(*A, ap, &off)) <= 0) {
        va_end(ap);
        return result;
    }
    va_end(ap);
    *(A->base + off) = e;
    return OK;
}
