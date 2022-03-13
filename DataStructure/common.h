//
//  common.h
//  DataStructure
//
//  Created by scfhao on 2022/3/13.
//

#ifndef common_h
#define common_h

// 函数结果状态码
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
// Status 是函数的类型，其值是函数结果状态代码
typedef int Status;

/**
 比较函数：比较函数用于对两个元素进行比较
 param one：参与比较的一个元素
 param other：参与比较的另一个元素
 return：TRUE/FALSE
 */
typedef Status (*CompareFunc)(void *one, void *other);

/**
 遍历函数：遍历一些数据结构中的元素时使用的函数
 param e：在遍历函数当前遍历的元素
 return：遍历函数返回值，返回失败时，停止遍历
 */
typedef Status (*VisitFunc)(void *e);

// 检查状态的通用函数
void checkStatus(Status status);

#endif /* common_h */
