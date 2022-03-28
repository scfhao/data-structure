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
    int *a = (int *)elem;
    printf("%d ", *a);
    return OK;
}

Status compareInt(void *one, void *other) {
    return *(int *)one == *(int *)other;
}

void testIntElemType(void) {
    printf("----------通用顺序表中存入int测试---------\n");
    USqList intList = InitUSqList(5, 2, sizeof(int));
    for (int i=0; i<10; i++) {
        int tmp = i+1;
        ListInsert_USq(intList, tmp, &tmp);
    }
    printf("在顺序表中存入了1-10，现在顺序表长度为:%d，元素有：", ListLength_USq(intList));
    ListTraverse_USq(intList, printInt);
    printf("\n");
    ListDelete_USq(intList, 5);
    printf("删除了第5个元素，现在长度变为：%d，元素有：", ListLength_USq(intList));
    ListTraverse_USq(intList, printInt);
    printf("\n");
    int eight = 8;
    int *prior = PriorElem_USq(intList, &eight, compareInt);
    int *next = NextElem_USq(intList, &eight, compareInt);
    printf("8前面的数字是%d,后面的数字是%d\n", *prior, *next);
    DestroyUSqList(intList);
    printf("---------------------------------------\n");
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
    printf("----------通用顺序表中存入struct测试---------\n");
    USqList structList = InitUSqList(4, 2, sizeof(Person));
    Person zhangsan = { "zhangsan", 18 };
    Person lisi = { "lisi", 19 };
    Person wangwu = { "wangwu", 20 };
    Person zhaoliu = { "zhaoliu", 21 };
    ListInsert_USq(structList, 1, &zhangsan);
    ListInsert_USq(structList, 2, &lisi);
    ListInsert_USq(structList, 3, &wangwu);
    ListInsert_USq(structList, 4, &zhaoliu);
    printf("在顺序表中存入了 4 个Person，现在顺序表长度为:%d，元素有：", ListLength_USq(structList));
    ListTraverse_USq(structList, printStruct);
    printf("\n");
    ListDelete_USq(structList, 2);
    printf("删除了第2个元素，现在长度变为：%d，元素有：", ListLength_USq(structList));
    ListTraverse_USq(structList, printStruct);
    printf("\n");
    Person *prior = PriorElem_USq(structList, &wangwu, compareStruct);
    if (prior) {
        printf("wangwu 前面是:");
        printStruct(prior);
    } else {
        printf("wangwu 前面没有人");
    }
    printf("\n");
    Person *next = NextElem_USq(structList, &zhaoliu, compareStruct);
    if (next) {
        printf("zhaoliu 后面是:");
        printStruct(next);
    } else {
        printf("zhaoliu 后面没有人");
    }
    printf("\n");
    DestroyUSqList(structList);
    printf("---------------------------------------\n");
}

// 测试在 USqList 中放指针元素
Status printPointerElem(void *elem) {
    char **string = (char **)elem;
    printf("%s ", *string);
    return OK;
}

Status compareCharPointer(void *one, void *other) {
    char **str1 = one, **str2 = other;
    return strcmp(*str1, *str2) == 0;
}

void testPointerElemType(void) {
    printf("----------通用顺序表中存入 pointer 测试---------\n");
    USqList ptrList = InitUSqList(4, 2, sizeof(char *));
    char *zhangsan = "zhangsan";
    char *lisi = "lisi";
    char *wangwu = "wangwu";
    char *zhaoliu = "zhaoliu";
    printf("1:%p %c\n", zhangsan, *zhangsan);
    printf("2:%p %c\n", lisi, *lisi);
    printf("3:%p %c\n", wangwu, *wangwu);
    printf("4:%p %c\n", zhaoliu, *zhaoliu);
    ListInsert_USq(ptrList, 1, &zhangsan);
    ListInsert_USq(ptrList, 2, &lisi);
    ListInsert_USq(ptrList, 3, &wangwu);
    ListInsert_USq(ptrList, 4, &zhaoliu);
    char **zhangsan2 = GetElem_USq(ptrList, 1);
    char **lisi2 = GetElem_USq(ptrList, 2);
    char **wangwu2 = GetElem_USq(ptrList, 3);
    char **zhaoliu2 = GetElem_USq(ptrList, 4);
    printf("%p-1-%p\n", zhangsan, *zhangsan2);
    printf("%p-2-%p\n", lisi, *lisi2);
    printf("%p-3-%p\n", wangwu, *wangwu2);
    printf("%p-4-%p\n", zhaoliu, *zhaoliu2);
    printf("在顺序表中存入了 4 个字符串，现在顺序表长度为:%d，元素有：", ListLength_USq(ptrList));
    ListTraverse_USq(ptrList, printPointerElem);
    printf("\n");
    ListDelete_USq(ptrList, 2);
    printf("删除了第2个元素，现在长度变为：%d，元素有：", ListLength_USq(ptrList));
    ListTraverse_USq(ptrList, printPointerElem);
    printf("\n");
    Person *prior = PriorElem_USq(ptrList, wangwu, compareCharPointer);
    if (prior) {
        printf("wangwu 前面是:");
        printPointerElem(prior);
    } else {
        printf("wangwu 前面没有人");
    }
    printf("\n");
    Person *next = NextElem_USq(ptrList, zhaoliu, compareCharPointer);
    if (next) {
        printf("zhaoliu 后面是:");
        printPointerElem(next);
    } else {
        printf("zhaoliu 后面没有人");
    }
    printf("\n");
    DestroyUSqList(ptrList);
    printf("---------------------------------------\n");
}

void testUSqList(void) {
//    testIntElemType();
//    testStructElemType();
    testPointerElemType();
}
