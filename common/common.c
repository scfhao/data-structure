//
//  common.c
//  DataStructure
//
//  Created by scfhao on 2022/3/13.
//

#include "common.h"
#include <stdio.h>
#include <stdlib.h>

// 检查状态的通用函数
void checkStatus(Status status) {
    switch (status) {
        case OK: return;
        case OVERFLOW:
            fprintf(stderr, "OVERFLOW");
            break;
        case INFEASIBLE:
            fprintf(stderr, "INFEASIBLE");
            break;
        default:
            break;
    }
    // 结束程序
    exit(status);
}
