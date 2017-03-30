//
//  ShellSort.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/3/27.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "ShellSort.h"
#include "Header.h"


void sSort(SqList *L){
    int i,j;
    int increment = L->length;//9
    //{0,9,1,5,8,3,7,4,2,6};
    do{
    
        increment = increment/3 + 1;//增量序列1
        //2---9  7
        for (i = increment +1; i <= L->length; i++) {
            
            if (L->r[i]<L->r[i -increment]) {
                 //{5,1,2,3,4,6,7,5,8,9};
                L->r[0] = L->r[i];
                for (j = i - increment; j > 0 && L->r[0]<L->r[j]; j -= increment) {
                   //{5,1,2,3,4,5,7,6,8,9};
                    L->r[j+increment] = L->r[j];
                }
                L->r[j+increment] = L->r[0];
            }
        }
    }while (increment > 1);
}
void shellSort(){
    SqList L;
    L.length = 9;
    int a[10] = {0,9,1,5,8,3,7,4,2,6};
    for (int i = 0; i < 10; i++) {
        L.r[i] = a[i];
    }
    sSort(&L);
    for (int i = 1; i < 10; i++) {
        printf("----%d\n",L.r[i]);
    }
}