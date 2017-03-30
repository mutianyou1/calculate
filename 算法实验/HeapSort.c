//
//  HeapSort.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/3/27.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "HeapSort.h"
#include "Header.h"
void heapAdjust(SqList *L,int s,int m){
    // s = 2        m = 9
    // a[10] = {0,50,10,90,60,70,40,80,30,20};
    int temp,j;
    temp = L->r[s];//50
    //沿着关键字较大孩子的节点向下筛选 每次把最大的筛选出来置顶
    for (j = 2*s; j<=m; j*=2) {// j = 8
        
        if (j < m && L->r[j] < L->r[j+1]) {
            ++j;
            
        }
        if (temp >=L->r[j]) {
            break;
        }
        L->r[s] = L->r[j];
        s = j;
       
    }
    L->r[s] = temp;
    
    
}

void hSort(SqList *L){
    int i;
    for (i = L->length/2; i > 0; i--) {
        //构建成大顶堆 从下到上将有孩子节点的子树调整，调整完了也就把整个调整好了
        heapAdjust(L, i, L->length);
    }
    
    for (i = L->length; i > 1; i--) {
        kswap(L, 1, i);//将堆顶的记录和未排序子序列最后一个记录交换
        //从1到i－1构建顶堆
        heapAdjust(L, 1, i - 1);
    }
}
void heapSort(){
    SqList L;
    L.length = 9;
    int a[10] = {0,50,10,90,30,70,40,80,60,20};
    for (int i = 0; i < 10; i++) {
        L.r[i] = a[i];
    }
    hSort(&L);
    for (int i = 1; i < 10; i++) {
        printf("----%d\n",L.r[i]);
    }


}