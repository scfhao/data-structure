//
//  TSMatrix.c
//  DataStructure
//
//  Created by hao on 2024/7/9.
//

#include "TSMatrix.h"

Status TransposeTSMatrix1(TSMatrix M, TSMatrix *T);
Status TransposeTSMatrix2(TSMatrix M, TSMatrix *T);

// 创建稀疏矩阵
Status CreateTSMatrix(TSMatrix *M) {
    return OK;
}

// 销毁稀疏矩阵
Status DestroyTSMatrix(TSMatrix *M) {
    return OK;
}

// 输出稀疏矩阵
Status PrintTSMatrix(TSMatrix M) {
    int i = 1, j = 1, p = 1;
    while (i <= M.mu && j <= M.nu) {
        if (j > 1 && j <= M.nu) printf("\t");
        if (M.data[p].i == i && M.data[p].j == j) {
            printf("%d", M.data[p].e);
            ++p;
        } else {
            printf("0");
        }
        ++j;
        if (j > M.nu) {
            // 超出列数，换行
            ++i;
            j = 1;
        }
    }
    return OK;
}

// 复制稀疏矩阵
Status CopyTSMatrix(TSMatrix M, TSMatrix *T) {
    return OK;
}

// 求稀疏矩阵的和
Status AddTSMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q) {
    return OK;
}

// 求稀疏矩阵的差
Status SubtTSMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q) {
    return OK;
}

// 求稀疏矩阵的乘积
Status MultTSMatrix(TSMatrix M, TSMatrix N, TSMatrix *Q) {
    return OK;
}

// 求稀疏矩阵的转置矩阵
Status TransposeTSMatrix(TSMatrix M, TSMatrix *T) {
//    return TransposeTSMatrix1(M, T);
    return TransposeTSMatrix2(M, T);
}

// 书中 p.99 算法 5.1
// 此算法内层循环每次都循环 tu 次，近适用于 tu << mu * nu 的情况下
Status TransposeTSMatrix1(TSMatrix M, TSMatrix *T) {
    // 创建 T
    Status createResult = CreateTSMatrix(T);
    if (createResult != OK) {
        // 创建T失败
        return createResult;
    }
    T->mu = M.nu;
    T->nu = M.mu;
    T->tu = M.tu;
    if (T->tu) {
        // q 变量用来存 T 矩阵三元表中的当前位置
        int q = 1;
        for (int col = 1; col <= M.nu; ++col) {
            for (int p = 1; p <= M.tu; ++p) {
                if (M.data[p].j == col) {
                    T->data[q].i = M.data[p].j;
                    T->data[q].j = M.data[p].i;
                    T->data[q].e = M.data[p].e;
                    ++q;
                }
            }
        }
    }
    return OK;
}

// 书中 p.100 算法 5.2
// 快速转置算法
Status TransposeTSMatrix2(TSMatrix M, TSMatrix *T) {
    // 创建 T
    Status createResult = CreateTSMatrix(T);
    if (createResult != OK) {
        // 创建T失败
        return createResult;
    }
    T->mu = M.nu;
    T->nu = M.mu;
    T->tu = M.tu;
    
    int num[M.nu + 1];
    int cpot[M.nu + 1];
    if (T->tu) {
        for (int col = 1; col <= M.nu; ++col) num[col] = 0;
        for (int t=1; t <= M.tu; ++t) ++num[M.data[t].j];   // 求M中每一列含非零元个数
        cpot[1] = 1;
        // 求第col列中第一个非零元在b.data中的序号
        for (int col = 2; col <= M.nu; ++col) cpot[col] = cpot[col - 1] + num[col - 1];
        for (int p = 0; p <= M.tu; ++p) {
            int col = M.data[p].j;
            int q = cpot[col];
            T->data[q].i = M.data[p].j;
            T->data[q].j = M.data[p].i;
            T->data[q].e = M.data[p].e;
            ++cpot[col];
        }
    }
    return OK;
}
