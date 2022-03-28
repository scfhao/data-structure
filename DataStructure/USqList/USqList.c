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
    if (capacity < 1 || incrementSize < 1) {
        return NULL;
    }
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
    return _list->elements+(index-1)*_list->typeSize;
}

int LocateElem_USq(USqList list, void *elem, CompareFunc compare) {
    _USqList * _list = (_USqList *)list;
    int i = 1;
    void *p = _list->elements;
    while (i <= _list->length && !(*compare)(p, elem)) {
        ++i;
        p+=_list->typeSize;
    }
    if (i <= _list->length) return i;
    else return 0;
}

void * PriorElem_USq(USqList list, void *cur_e, CompareFunc compare) {
    int cur = LocateElem_USq(list, cur_e, compare);
    _USqList * _list = (_USqList *)list;
    if (cur < 2 || cur > _list->length) return NULL;
    return _list->elements+(cur-2)*_list->typeSize;
}

void * NextElem_USq(USqList list, void *cur_e, CompareFunc compare) {
    int cur = LocateElem_USq(list, cur_e, compare);
    _USqList * _list = (_USqList *)list;
    if (cur < 1 || cur >= _list->length) return NULL;
    return _list->elements+cur*_list->typeSize;
}

Status ListInsert_USq(USqList list, int i, void *element) {
    _USqList * _list = (_USqList *)list;
    if (i < 1 || i > _list->length + 1) return ERROR;
    if (_list->length >= _list->capacity) {
        void *elements = realloc(_list->elements, (_list->capacity + _list->increament)*_list->typeSize);
        if (!elements) {
            return OVERFLOW;
        }
        _list->elements = elements;
        _list->capacity += _list->increament;
    }
    for (void *p = _list->elements+_list->length*_list->typeSize; p >= _list->elements+_list->typeSize*i; p-=_list->typeSize) {
        memcpy(p, p-_list->typeSize, _list->typeSize);
    }
    memcpy(_list->elements+(i-1)*_list->typeSize, element, _list->typeSize);
    _list->length++;
    return 1;
}

Status ListDelete_USq(USqList list, int i) {
    _USqList * _list = (_USqList *)list;
    if (i < 1 || i > _list->length) return ERROR;
    for (int j=i-1; j<_list->length-1; j++) {
        memcpy(_list->elements+j*_list->typeSize, _list->elements+_list->typeSize*(j+1), _list->typeSize);
    }
    _list->length--;
    return OK;
}

Status ListTraverse_USq(USqList list, VisitFunc visit) {
    _USqList * _list = (_USqList *)list;
    for (int i=0; i<_list->length; i++) {
        if (!(*visit)(_list->elements+i*_list->typeSize)) {
            return ERROR;
        }
    }
    return OK;
}
