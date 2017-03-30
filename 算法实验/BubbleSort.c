//
//  BubbleSort.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/3/24.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "BubbleSort.h"
#include "Header.h"

//按从小到大排序
void bubbleSortFake(SqList *L){
    //[1,4,2,7]会因为排序还是把不是最大的放在最下面
    for (int i = 1; i < L->length; i++) {
        
        for (int k = i + 1; k <= L ->length; k++) {
            if (L->r[i] > L->r[k] ) {
                kswap(L, i, k);
            }
        }
    }

}
void bubuleSortNormal(SqList *L){
  

    for (int i = 1; i < L ->length; i++) {
        for (int k = L ->length - 1; k >= i; k--) {
            if (L->r[k] > L->r[k+1]) {
                kswap(L, k, k+1);
             
            }
        }
    }
}

void bubuleSortHigh(SqList *L){
    
    //    int a[10] = {0,2,1,3,4,5,6,7,8,9};
    int flag = 1;
    for (int i = 1; i < L ->length && flag == 1; i++) {
        flag = 0;
        for (int k = L ->length -1; k >= i; k--) {
            if (L->r[k] > L->r[k+1]) {
                kswap(L, k, k+1);
                flag = 1;
            }
        }
    }
}
void bubbleSort(){
    SqList L;
    L.length = 9;
    //int a[10] = {0,9,1,5,8,3,7,4,2,6};
    int  a[10] = {0,2,1,3,4,5,6,7,8,9};
    for (int i = 0; i < 10; i++) {
        L.r[i] = a[i];
    }
    bubbleSortFake(&L);
    bubuleSortNormal(&L);
    bubuleSortHigh(&L);
    for (int i = 1; i < 10; i++) {
        //printf("----%d\n",L.r[i]);
    }
    
}