//
//  SimpleSelectSort.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/3/24.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "SimpleSelectSort.h"
#include "Header.h"

void simpleSelect(SqList *L){
    //int a[10] = {0,9,1,5,8,3,7,4,2,6};
    for (int i = 1; i < L->length; i++) {
        int min = i;//1-->9
        for (int k = L ->length - 1; k >= i; k--) {
            if (L->r[min] > L->r[k+1]) {
                min = k+1;
            }
        }
        if (min != i) {
            kswap(L, i, min);
        }
        
    }
}


void simpleSelectSort(){
    SqList L;
    L.length = 9;
    int a[10] = {0,9,1,5,8,3,7,4,2,6};
    //int  a[10] = {0,2,1,3,4,5,6,7,8,9};
    for (int i = 0; i < 10; i++) {
        L.r[i] = a[i];
    }
    simpleSelect(&L);
    for (int i = 1; i < 10; i++) {
        printf("----%d\n",L.r[i]);
    }
    


}