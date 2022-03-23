//
//  USqList.c
//  DataStructure
//
//  Created by scfhao on 2022/3/23.
//

#include "USqList.h"
#include <malloc/_malloc.h>
#include <string.h>

typedef struct {
    int capacity;   // 容量，即够存多少个元素
    int increament; // 增量，容量不够时容量的增量
    int typeSize;   // 一个元素的内存大小
    int length;     // 有几个元素
    void *elements; // 元素数组
} _USqList;

USqList InitUSqList(int capacity, int incrementSize, int typeSize) {
    _USqList *list = malloc(sizeof(_USqList));
    list->capacity = capacity;
    list->increament = incrementSize;
    list->typeSize = typeSize;
    list->length = 0;
    list->elements = malloc(list->capacity*list->typeSize);
    return list;
}

void DestroyUSqList(USqList list) {
    _USqList * _list = (_USqList *)list;
    free(_list->elements);
    free(_list);
}

void ClearUSqList(USqList list) {
    _USqList * _list = (_USqList *)list;
    _list->length = 0;
}

int ListEmpty_USq(USqList list) {
    _USqList * _list = (_USqList *)list;
    return _list->length == 0;
}

int ListLength_USq(USqList list) {
    _USqList * _list = (_USqList *)list;
    return _list->length;
}

void * GetElem_USq(USqList list, int index) {
    _USqList * _list = (_USqList *)list;
    if (index < 1 || index > _list->length) {
        return NULL;
    }
    return _list->elements+index-1;
}

int LocateElem_USq(USqList list, void *elem, CompareFunc compare) {
    _USqList * _list = (_USqList *)list;
    int i = 1;
    void *p = _list->elements;
    while (i <= _list->length && !(*compare)((void *)*p, elem)) {
        ++i;
        p++;
    }
    if (i <= _list->length) return i;
    else return 0;
}

int add(USqList list, void *element) {
    _USqList * _list = (_USqList *)list;
    if (_list->length >= _list->capacity) {
        _list->elements = realloc(_list->elements, (_list->capacity + _list->increament)*_list->typeSize);
        if (!_list->elements) {
            return -1;
        }
        _list->capacity += _list->increament;
    }
    memcpy(_list->elements+(_list->length*_list->typeSize), element, _list->typeSize);
    _list->length++;
    return 1;
}

Status ListTraverse_USq(USqList L, VisitFunc visit) {
    for (int i=0; i<L.length; i++) {
        if (!(*visit)((void *)L.elem[i])) {
            return ERROR;
        }
    }
    return OK;
}
