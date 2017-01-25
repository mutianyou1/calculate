//
//  KMP.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/1/12.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "KMP.h"

#define Main_size 7
#define Sub_size 3

void getNext(char *string, int *next){
    int i ,j;
    i = 1;
    j = 0;
    
    next[1] = 0;
    
    while (i < Sub_size) {
       
        if (j == 0 || string[i] == string[j]) {
            ++i;
            ++j;
            next[i] = j;
            //优化
//            if (string[i] != string[j]) {
//                next[i] = j;
//            }else{
//                next[i] = next[j];
//            }
        }else{
            j = next[j];
        }
    }
}

int index_KMP(char *mainString, char *subString, int pos){
    int i = pos;
    int j = 1;
    
    int next[4];
    // X012
    getNext(subString, next);
    while (i <= Main_size && j <= Sub_size) {
        
        if (j == 0 || mainString[i] == subString[j]) {
            ++i;
            ++j;
            //correct j = 4 i = 8
            //wrong j = 1 i = 8
        }else{
            j = next[j];//j =2  i = 7
        }
    }
    
    if (j > Sub_size) {
        return i  - Sub_size;
    }
    return 0;
}
void printKMPNextArray(){
    printf("查找子位置--%d",index_KMP("Xbadgooc", "Xooc", 0));
}