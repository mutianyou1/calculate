//
//  QuickSort.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/3/29.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "QuickSort.h"
#include "Header.h"
//数组长度阀值
#define MAX_LENGTH_INSERT_SORT 7
//优化
int partitionHighQuality(SqList *L,int low, int high){
    //如{0,9,1,5,8,3,7,4,6,2};给出的返回值不是中间的数字
    //运算一遍后为 {0,2,1,5,8,3,7,4,6,9};只是交换了一次
    //优化三数取中法
    int m = low + (high - low)/2;
    if (L->r[low] > L->r[high]) {
        kswap(L, low, high);//左端较小
    }
    if (L->r[m] > L->r[high]) {
        kswap(L, high, m);//中间较小
    }
    if (L->r[m] > L->r[low]) {
        kswap(L, m, low);//左端为中间数
    }
    
    int pivotkey;
    pivotkey = L->r[low];//预先用第一个数字做枢轴值
    L->r[0] = pivotkey;//减少交换次数预存
    
    while (low < high) {//从表的两段向中间轮询求出枢轴值
        //如{0,9,1,5,8,3,7,4,6,2};
        while (low < high && L->r[high] >= pivotkey) {
            high --;
        }
        L->r[low] = L->r[high];
        //kswap(L, low, high);
        while (low < high && L->r[low] <= pivotkey) {
            low++;
        }
        L->r[high] = L->r[low];
        //kswap(L, low, high);
    }
    L->r[low] = L->r[0];
    return low;
}
int partition(SqList *L,int low, int high){
    int pivotkey;
    pivotkey = L->r[low];//预先用第一个数字做枢轴值
    
    while (low < high) {//从表的两段向中间轮询求出枢轴值
    
        while (low < high && L->r[high] >= pivotkey) {
            high --;
        }
        kswap(L, low, high);
        while (low < high && L->r[low] <= pivotkey) {
            low++;
        }
        kswap(L, low, high);
    }
    return low;
}

void quickSortList(SqList *L,int low,int high){
    int pivot;
    if (low < high) {
        pivot = partition(L,low,high);//将r分为两段，算出枢轴值pivot
        quickSortList(L,low,pivot-1);//低子表递归
        quickSortList(L,pivot+1,high);//高子表递归
    }
    
}
void kInsertSort(SqList *L){
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
//如果数组长度较小还用递归就造成了大材小用的浪费
void quickSortListShort(SqList *L,int low,int high){
    int pivot;
    if (high - low > MAX_LENGTH_INSERT_SORT) {
        while(low < high) {//while方式迭代减少递归深度
            pivot = partition(L,low,high);//将r分为两段，算出枢轴值pivot
            quickSortListShort(L,low,pivot-1);//低子表递归
            low = pivot + 1;//尾递归优化
        }
        
    }else{
         kInsertSort(L);
    }
}
void quickSort(){

    SqList L;
    L.length = 9;
    int a[10] = {0,50,10,90,30,70,40,80,60,20};
    //int  a[10] = {0,9,1,5,8,3,7,4,6,2};
    for (int i = 0; i < 10; i++) {
        L.r[i] = a[i];
    }
    //quickSortList(&L,1,L.length);
    quickSortListShort(&L, 1, L.length);
    for (int i = 1; i < 10; i++) {
        printf("----%d\n",L.r[i]);
    }

}