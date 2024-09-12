//
//  TSMatrix.h
//  DataStructure
//
//  Created by hao on 2024/7/9.
//  三元组顺序表稀疏矩阵 page 98.

#ifndef TSMatrix_h
#define TSMatrix_h

#include <stdio.h>
#include "common.h"

typedef int ElemType;

#define MAXSIZE 12500   // 假设非零元个数的最大值为12500

typedef struct {
    int i, j;   // 该非零元的行下标和列下标
    ElemType e;
} Triple;

typedef struct {
    Triple data[MAXSIZE + 1];   // 非零元三元组表，data[0]未用
    int mu, nu, tu;             // 矩阵的行数、列数和非零元个数
} TSMatrix;

//----- 基本操作 -----

// 创建稀疏矩阵
Status CreateTSMatrix(TSMatrix *M);

// 销毁稀疏矩阵
Status DestroyTSMatrix(TSMatrix *M);

// 输出稀疏矩阵
Status PrintTSMatrix(TSMatrix M);

// 复制稀疏矩阵
Status CopyTSMatrix(TSMatrix M, TSMatrix *T);

// 求稀疏矩阵的和
Status AddTSMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q);

// 求稀疏矩阵的差
Status SubtTSMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q);

// 求稀疏矩阵的乘积
Status MultTSMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q);

// 求稀疏矩阵的转置矩阵
Status TransposeTSMatrix(TSMatrix M, TSMatrix *T);

#endif /* TSMatrix_h */
