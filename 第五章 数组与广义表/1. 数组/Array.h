//
//  Array.h
//  DataStructure
//
//  Created by hao on 2024/7/4.
//  数组的顺序存储表示和实现

#ifndef Array_h
#define Array_h

#include <stdio.h>
#include "common.h"
// 标准头文件，提供宏 va_start、va_arg 和 va_end，用于存取变长参数表
#include <stdarg.h>

// 假设数组维数的最大值为 8
#define MAX_ARRAY_DIM 8

// 定义元素类型为字符串
typedef int ElemType;

typedef struct {
    ElemType *base; // 数组元素基址，由 InitArray 分配
    int dim;        // 数组维数目
    int *bounds;    // 数组维界基址，由 InitArray 分配
    int *constants; // 数组映像函数常量基址，由 InitArray 分配
} Array;

//----- 基本操作的函数原型说明 -----

/// 若维数 dim 和随后的个各维长度合法，则构造相应的数组 A，并返回 OK
Status InitArray(Array *A, int dim, ...);

/// 销毁数组 A
Status DestroyArray(Array *A);

/// A 是 n 维数组，e为元素变量，随后是 n 个下标值。
/// 若各下标不超界，则 e 赋值为所指定的 A 的元素，并返回 OK
Status Value(Array A, ElemType *e, ...);

/// A 是 n 维数组，e 为元素变量，随后是 n 个下标值。
/// 若下标不超界，则将 e 的值赋值给指定的 A 的元素，并返回 OK
Status Assign(Array *A, ElemType e, ...);

#endif /* Array_h */
