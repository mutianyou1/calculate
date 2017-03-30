//
//  Binary_search.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/3/21.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "Binary_search.h"
#include "Header.h"
typedef int F[MAXSIZE];
int search(int *a,int n,int key){

    int low,mid,high;
    low = 1;
    high = n;
    //key = 5
    // [0,1,5,9,7,15,18,22]
    while (low <= high) {
        printf("---search---\n");
        //mid = (high + low)/2;
        //改进
        mid = low + (high - low)*(key -a[low])/(a[high] - a[low]);
        if (a[mid] > key) {
            high = mid - 1;//high=1 low=1
        }else if (a[mid] < key){
            low = mid + 1;
        }else{
            return mid;
        }
    }
    return 0;
}

int getFeboNaye_(int i){
    return i > 2 ? getFeboNaye_(i - 1) + getFeboNaye_(i - 2) : 1;
}
int finbonacci_Search(int *a, int n,int key){
    int mid,high,low,i,k;
    low = 1;
    high = n;
    k = 0;
    
    int F[n];
    F[0] = 0;
    //F[] = [0,1,1,2,3,5,8,13,21,34,55];
    for (i = 1; i < n; i++) {
        F[i] = getFeboNaye_(i);
    }
    while (F[k] - 1 < n) {
        k++;
        //k == 7
    }
   // 10 ---> 13
    // a = [0,1,16,24,35,47,59,62,73,88,99,99];
    //补全防止错误例如最后的99
    for (i = n; i < F[k] - 1; i++) {
        a[i] = a[n];
    } //F[] = [0,1,1,2,3,5,8,13,21,34,55];
     // a =   [0,1,16,24,35,47,59,62,73,88,99,99];
    while (low <= high) {//low = 1
        printf("---search---\n");
        mid = low + F[k -1] - 1;// mid = 11
        if (key < a[mid]) {
            high = mid - 1;//high=6
            k = k -1;//3
        }else if (key > a[mid]){
            low = mid + 1;//low = 9
            k = k  - 2;//k = 5
        }else{
            if (mid <= n) {
                return mid;
            }else{
                return n;
            }
        }
    }
   
    
    
    
    return 0;
}
void binarySearch(){
    int array[14] ;
    array[0] = 0;
    array[1] = 1;
    array[2] = 16;
    array[3] = 24;
    array[4] = 35;
    array[5] = 47;
    array[6] = 59;
    array[7] = 62;
    array[8] = 73;
    array[9] = 89;
    array[10] = 99;
    
    //int index = search(array, 10, 16);
    int index = finbonacci_Search(array, 10, 1);
    printf("index:%d\n",index);
}

