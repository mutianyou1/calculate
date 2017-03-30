//
//  StraightInertionSort.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/3/27.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "StraightInertionSort.h"
#include "Header.h"

//性能上移动和比较平均为n^2/4比选择和冒泡好
void insertionSort(SqList *L){
    int i,j;
    //int a[10] = {0,9,1,5,8,3,7,4,2,6};
    for (i = 2; i <= L ->length; i++) {
        if (L->r[i] < L->r[i-1]) {
            //小的数往[0]放
            L->r[0] = L->r[i]; //{7,1,3,4,5,7,8,9,2,6};
            for (j = i - 1; L ->r[j] > L->r[0]; j--) {//
                //
                L->r[j+1] = L->r[j];
            }
            //
            L->r[j+1] = L->r[0];
        }
    }
    
}
void straightInertionSort(){
    
    SqList L;
    L.length = 9;
    int a[10] = {0,9,1,5,8,3,7,4,2,6};
    for (int i = 0; i < 10; i++) {
        L.r[i] = a[i];
    }
    insertionSort(&L);
    for (int i = 1; i < 10; i++) {
        printf("----%d\n",L.r[i]);
    }
}