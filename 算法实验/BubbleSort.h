//
//  BubbleSort.h
//  算法实验
//
//  Created by 潘元荣(外包) on 17/3/24.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#ifndef BubbleSort_h
#define BubbleSort_h


/*
 各种排序性能比较
 
 比较--交换
 冒泡:最坏：n*(n-1)/2--n*(n-1)/2  最好：n-1 ---0
 简单选择：最坏：n*(n-1)/2--n-1       最好：n*(n-1)/2 --0
 插入：最坏：(n+2)*(n-1)/2--(n+4)*(n-1)/2 最好：n-1---0
 
 插入排序基本有序很少需要插入情况下性能是三者中最好的？？
 
 希尔排序：并不稳定但打破n*n的高效算法
 堆排序： 复杂度(nlongn)由于跳跃比较也不稳定
 
 
 */
#include <stdio.h>
void bubbleSort();
#endif /* BubbleSort_h */
