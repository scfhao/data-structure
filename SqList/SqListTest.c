//
//  SqListTest.c
//  DataStructure
//
//  Created by scfhao on 2022/3/13.
//

#include "SqListTest.h"
#include "SqList.h"
#include <stdlib.h>
#include <string.h>

// visit 函数举例
Status visit_SqList_int(void *e) {
    char ch = (ElemType)e;
    printf("%c", ch);
    return OK;
}

// 打印线性表内容
void printSqList(SqList L) {
    printf("线性表中内容为:");
    ListTraverse_Sq(L, &visit_SqList_int);
    printf("\n");
}

// compare 函数举例
Status Compare_Char_Sq(void *one, void *other) {
    char ch1 = (ElemType)one, ch2 = (ElemType)other;
    return ch1 == ch2;
}

// 测试线性表的功能
void testSqList() {
    printf("-----线性表-----\n");
    SqList list = {};
    Status status;
    // 创建线性表
    status = InitList_Sq(&list);
    checkStatus(status);
    printf("线性表初始化完成\n");
    // 往线性表里添加几个值
    printf("在线性表中插入:Hello World！");
    char *helloWorld = "Hello World!";
    for (int i=0; i<strlen(helloWorld); i++) {
        // 把 "Hello World!" 中的字符一个一个插入线性表中
        status = ListInsert_Sq(&list, i+1, helloWorld[i]);
        checkStatus(status);
    }
    // 打印看看线性表中当前的内容
    printSqList(list);
    // 查看线性表的长度
    printf("线性表长度：%d\n", ListLength_Sq(list));
    // 从线性表中获取一个元素
    char ch;
    status = GetElem_Sq(list, 5, &ch);
    checkStatus(status);
    printf("线性表中第 5 个元素是：%c\n", ch);
    // 查看某个元素在线性表中哪个位置
    int loc = LocateElem_Sq(list, 'l', &Compare_Char_Sq);
    if (loc == 0) {
        printf("在 Hello World！中找不到 l\n");
    } else {
        printf("l 元素在 Hello World！中第 %d 位\n", loc);
    }
    // 从线性表中获取 r 元素的前驱/后继
    status = PriorElem_Sq(list, 'r', &ch, &Compare_Char_Sq);
    checkStatus(status);
    printf("r 元素的前驱是 %c\n", ch);
    status = NextElem_Sq(list, 'r', &ch, &Compare_Char_Sq);
    checkStatus(status);
    printf("r 元素的后继是 %c\n", ch);
    // 从线性表中删除元素
    status = ListDelete_Sq(&list, 1, &ch);
    checkStatus(status);
    printf("从线性表中删除第 1 个元素 %c 后，线性表长度变为 %d\n", ch, ListLength_Sq(list));
    printSqList(list);
    // 把线性表重置为空表
    printf("把线性表重置为空表\n");
    ClearList_Sq(&list);
    // 检查是否为空表
    printf("现在线性表%s空表\n", ListEmpty_Sq(list) ? "是": "不是");
    // 销毁现行表
    status = DestroyList_Sq(&list);
    checkStatus(status);
    printf("线性表释放\n--------------\n\n");
}

