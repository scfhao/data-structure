//
//  SqList.h
//  DataStructure
//
//  Created by scfhao on 2022/3/13.
//

#ifndef SqList_h
#define SqList_h

#include <stdio.h>
#include "common.h"

// 定义线性表中存放的元素为字符串
typedef char ElemType;

/**
 线性表顺序存储结构--顺序表的实现
 */
typedef struct {
    ElemType *elem; // 存储空间基址
    int length;     // 当前长度
    int listsize;   // 当前分配的存储容量
} SqList;

// 构造一个空的线性表表
Status InitList_Sq(SqList *L);
// 销毁线性表
Status DestroyList_Sq(SqList *L);
// 将线性表重置为空表
Status ClearList_Sq(SqList *L);
// 判断线性表是否为空表
Status ListEmpty_Sq(SqList L);
// 返回 L 中的数据元素个数。
Status ListLength_Sq(SqList L);
// 用 e 返回 L 中第 i 个数据元素的值。
Status GetElem_Sq(SqList L, int i, ElemType *e);
// 返回 L 中第 1 个与 e 满足关系 compare() 的数据元素的位序。若这样的数据元素不存在，则返回值为 0。
Status LocateElem_Sq(SqList L, ElemType e, CompareFunc compare);
// 若 cur_e 是 L 的数据元素，且不是第一个，则用 pre_e 返回它的前驱，否则操作失败，pre_e 无定义。
Status PriorElem_Sq(SqList L, ElemType cur_e, ElemType *pre_e, CompareFunc compare);
// 若 cur_e 是 L 的数据元素，且不是最后一个，则用 next_e 返回它的后继，否则操作失败，next_e 无定义。
Status NextElem_Sq(SqList L, ElemType cur_e, ElemType *next_e, CompareFunc compare);
// 在 L 中第 i 个位置之前插入新的数据元素 e，L 的长度加 1。
Status ListInsert_Sq(SqList *L, int i, ElemType e);
// 删除 L 的第 i 个数据元素，并用 e 返回其值，L 的长度减 1。
Status ListDelete_Sq(SqList *L, int i, ElemType *e);
// 依次对 L 的每个数据元素调用函数 visit()。
Status ListTraverse_Sq(SqList L, VisitFunc visit);

#endif /* SqList_h */
