//
//  MergeSort.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/3/28.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "MergeSort.h"
#include "Header.h"

void Merge(int SR[],int TR[],int i,int m,int n){
    //int a[10] = {0,50,10,90,30,70,40,80,60,20}; m == n = 5
    int j,k,l;
    for (j = m+1 ,k = i; i<= m &&j <= n; k++) {
        if (SR[i] < SR[j]) {
            TR[k] = SR[i++];
        }else{
            TR[k] = SR[j++];
        }
    }
    if (i <= m) {
        for (l = 0; l <= m-1; l++) {
            TR[k+l] = SR[i+l];
        }
    }
    if (i <= n) {
        for (l = 0; l <= n -j; l++) {
            TR[k+l] = SR[j+l];
        }
    }
    
    
}

void MSort(int SR[],int TR1[],int s,int t){
    
    int m;
    int TR2[MAXSIZE+1];
    //int a[10] = {0,50,10,90,30,70,40,80,60,20};
    if (s == t) {
        TR1[s] = SR[s];
    }else{
        //将SR[s...t] 平分为SR[s..m]  SR[m+1...t]
        m = (s+t)/2;//m=5  s=1 t=9
        //将SR[s..m]递归为有序的TR2[s...m]
        MSort(SR,TR2,s,m);//1 5
        //将SR[m+1..t]递归为有序的TR2[m+1...t]
        MSort(SR,TR2,m+1,t);//6 9
        //合并
        Merge(TR2,TR1,s,m,t);
    }
    
    
}

void mergePass(int SR[],int TR[],int s,int n){
    int i ,j;
    i = 1;
    while (i<= n - 2 *s +1) {
        Merge(SR, TR, i, i+s-1, i +2 *s - 1);
        i = i + 2 *s;
    }
    //掉尾的数放到尾部
    if (i < n - s+1) {
        Merge(SR, TR, i, i+s-1, n);
    }else{
        for ( j = i; j <= n; j++) {
            TR[j] = SR[j];
        }
    }
    
}
void mergeSortNormal(SqList *L){
    int *TR = (int*)malloc(sizeof(int)*L->length);
    int k = 1;
    while (k < L->length) {
       
        mergePass(L->r,TR,k,L->length);
        //子序列长度加倍
        k = 2 *k;    
        mergePass(TR,L->r,k,L->length);
       //子序列长度加倍???
        k = 2 *k;
    }
   
}
void mergeSort(){
    SqList L;
    L.length = 9;
    int a[10] = {0,50,10,90,30,70,40,80,60,20};
    for (int i = 0; i < 10; i++) {
        L.r[i] = a[i];
    }
    MSort(L.r, L.r, 1, L.length);
    //mergeSortNormal(&L);
    for (int i = 1; i < 10; i++) {
        printf("----%d\n",L.r[i]);
    }


}