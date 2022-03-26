//
//  USqListTest.c
//  DataStructure
//
//  Created by scfhao on 2022/3/23.
//

#include "USqListTest.h"
#include "USqList.h"
#include <string.h>

// 测试在 USqList 中放 char 类型的元素
Status printInt(void *elem) {
    int a = (int)elem;
    printf("%d ", a);
    return OK;
}

Status compareInt(void *one, void *other) {
    return one == other;
}

void testIntElemType(void) {
    printf("----------通用顺序表中存入int测试---------\n");
    USqList intList = InitUSqList(10, 2, sizeof(int));
    for (int i=0; i<10; i++) {
        ListInsert_USq(intList, i, (void *)(i+1));
    }
    printf("在顺序表中存入了1-10，现在顺序表中的元素有：");
    ListTraverse_USq(intList, printInt);
    
}

// 测试在 USqList 中放结构体元素
typedef struct {
    char name[10];
    int age;
} Person;

Status printStruct(void *elem) {
    Person *p = elem;
    printf("[Person:<%s,%d>]", p->name, p->age);
    return OK;
}

// 比较两个结构体是否相等
Status compareStruct(void *one, void *other) {
    Person *p1 = one, *p2 = other;
    return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

void testStructElemType(void) {
    
}

// 测试在 USqList 中放指针元素
void printPointerElem(void *elem) {
    char *string = (char *)elem;
    printf("%s", string);
}

Status compareCharPointer(void *one, void *other) {
    char *str1 = one, *str2 = other;
    return strcmp(str1, str2) == 0;
}

void testPointerElemType(void) {
    
}

void testUSqList(void) {
    testIntElemType();
    testStructElemType();
    testPointerElemType();
}
