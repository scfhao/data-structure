//
//  SqList.c
//  DataStructure
//
//  Created by scfhao on 2022/3/13.
//

#include "SqList.h"
#include <malloc/_malloc.h>
#include <string.h>

#define LIST_INIT_SIZE 100 // 线性表存储空间的初始分配量
#define LISTINCREMENT 10 // 线性表存储空间的分配增量

/**
 操作结果：构造一个空的线性表 L。
 */
Status InitList_Sq(SqList *L) {
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    // 原书这里内存分配失败时，直接调用了 exit(OVERFLOW);
    // 中止了程序，个人认为是否需要退出程序应由调用方决定
    if (!L->elem) return OVERFLOW;
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

/**
 初始条件：线性表 L 已存在。
 操作结果：销毁线性表 L。
 */
Status DestroyList_Sq(SqList *L) {
    if (!L->elem) return ERROR;
    free(L->elem);
    L->length = 0;
    L->listsize = 0;
    return OK;
}

/**
 初始条件：线性表 L 已存在。
 操作结果：将 L 重置为空表。
 */
Status ClearList_Sq(SqList *L) {
    if (!L->elem) return ERROR;
    L->length = 0;
    return OK;
}

/**
 初始条件：线性表 L 已存在。
 操作结果：若 L 为空表，则返回 TRUE，否则返回 FALSE。
 */
Status ListEmpty_Sq(SqList L) {
    return L.length == 0;
}

/**
 初始条件：线性表 L 已存在。
 操作结果：返回 L 中的数据元素个数。
 */
int ListLength_Sq(SqList L) {
    return L.length;
}

/**
 初始条件：线性表 L 已存在，1<=i<=ListLength_Sq(L)。
 操作结果：用 e 返回 L 中第 i 个数据元素的值。
 */
Status GetElem_Sq(SqList L, int i, ElemType *e) {
    if (i < 1 || i > L.length) return ERROR;
    *e = L.elem[i-1];
    return OK;
}

/**
 初始条件：线性表 L 已存在，compare() 是数据元素判定函数。
 操作结果：返回 L 中第 1 个与 e 满足关系 compare() 的数据元素的位序。若这样的数据元素不存在，则返回值为 0。
 */
int LocateElem_Sq(SqList L, ElemType e, CompareFunc compare) {
    int i = 1;
    ElemType *p = L.elem;
    while (i <= L.length && !(*compare)((void *)*p++, (void *)e)) ++i;
    if (i <= L.length) return i;
    else return 0;
}

/**
 初始条件：线性表 L 已存在。
 操作结果：若 cur_e 是 L 的数据元素，且不是第一个，则用 pre_e 返回它的前驱，否则操作失败，pre_e 无定义。
 */
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType *pre_e, CompareFunc compare) {
    int cur = LocateElem_Sq(L, cur_e, compare);
    if (cur <= 1 || cur > L.length) return ERROR;
    *pre_e = L.elem[cur-2];
    return OK;
}

/**
 初始条件：线性表 L 已存在。
 操作结果：若 cur_e 是 L 的数据元素，且不是最后一个，则用 next_e 返回它的后继，否则操作失败，next_e 无定义。
 */
Status NextElem_Sq(SqList L, ElemType cur_e, ElemType *next_e, CompareFunc compare) {
    int cur = LocateElem_Sq(L, cur_e, compare);
    if (cur < 1 || cur >= L.length) return ERROR;
    *next_e = L.elem[cur];
    return OK;
}

/**
 初始条件：线性表 L 已存在，1<=i<=ListLength_Sq(L)+1。
 操作结果：在 L 中第 i 个位置之前插入新的数据元素 e，L 的长度加 1。
 */
Status ListInsert_Sq(SqList *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) return ERROR;
    if (L->length >= L->listsize) {
        ElemType *newbase = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if (!newbase) return OVERFLOW;
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }
    ElemType *q = &L->elem[i-1];
    for (ElemType *p = &L->elem[L->length - 1]; p >= q; --p) *(p+1) = *p;
    *q = e;
    ++L->length;
    return OK;
}

/**
 初始条件：线性表 L 已存在，1<=i<=ListLength_Sq(L)。
 操作结果：删除 L 的第 i 个数据元素，并用 e 返回其值，L 的长度减 1。
 */
Status ListDelete_Sq(SqList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) return ERROR;
    ElemType *p = &L->elem[i-1];
    e = p;
    ElemType *q = L->elem + L->length - 1;
    for (++p; p <= q; ++p) *(p-1) = *p;
    --L->length;
    return OK;
}

/**
 初始条件：线性表 L 已存在。
 操作结果：依次对 L 的每个数据元素调用函数 visit()。一旦 visit() 失败，则操作失败。
 */
Status ListTraverse_Sq(SqList L, VisitFunc visit) {
    for (int i=0; i<L.length; i++) {
        if (!(*visit)((void *)L.elem[i])) {
            return ERROR;
        }
    }
    return OK;
}
