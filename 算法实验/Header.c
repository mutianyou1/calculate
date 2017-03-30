//
//  Header.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/1/25.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "Header.h"

void kswap(SqList *L, int i ,int j){
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}