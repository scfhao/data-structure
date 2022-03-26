//
//  USqList.h
//  DataStructure
//
//  Created by scfhao on 2022/3/23.
//

#ifndef USqList_h
#define USqList_h

#include <stdio.h>
#include "common.h"

typedef void * USqList;

USqList InitUSqList(int capacity, int incrementSize, int typeSize);
void DestroyUSqList(USqList list);
void ClearUSqList(USqList list);
int ListEmpty_USq(USqList list);
int ListLength_USq(USqList list);
void * GetElem_USq(USqList list, int index);
int LocateElem_USq(USqList list, void *elem, CompareFunc compare);
void * PriorElem_USq(USqList list, void *cur_e, CompareFunc compare);
void * NextElem_USq(USqList list, void *cur_e, CompareFunc compare);
Status ListInsert_USq(USqList list, int i, void *element);
Status ListDelete_USq(USqList list, int i);
Status ListTraverse_USq(USqList list, VisitFunc visit);

#endif /* USqList_h */
