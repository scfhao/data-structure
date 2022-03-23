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


#endif /* USqList_h */
