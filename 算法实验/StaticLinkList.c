//
//  StaticLinkList.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/1/11.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "StaticLinkList.h"

#define MAXSIZE 1000


typedef enum {
    OK,
    ERROR,
    UNKONW,
} Status;

//组件
typedef struct {
    char *name;
    int cur;
}Component,StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space){
 
    int i = 0;
    for (i = 0; i < MAXSIZE; i++) {
        space[i].cur = i + 1;
        space[i].name = " ";
    }
    space[MAXSIZE - 1].cur = 0;
    return OK;
}
int ListLength(StaticLinkList list){
    int j = 0;
    int i = list[MAXSIZE - 1].cur;
    while (i) {
        i = list[i].cur;
        j++;
    }
    return j;
}

int Malloc_SLL(StaticLinkList space){
    int i = space[0].cur;
    
    if (space[0].cur) {
        space[0].cur = space[i].cur;
    }
    
    return i;
}
void Free_SLL(StaticLinkList list, int i){

    list[i].cur = list[0].cur;
    list[i].name = "";
    list[0].cur = i;
}
Status ListDelete(StaticLinkList list, int i){
    
    int j , k;
    
    if (i < 1 || i > ListLength(list)) {
        return ERROR;
    }
    
    k = MAXSIZE  - 1;
    
    for (j = 1; j < i; j++){
        k = list[k].cur;
    }
    j = list[k].cur;
    list[k].cur = list[j].cur;
    
    Free_SLL(list, j);
    return OK;
}
//在i 位置插入 数据
Status ListInsert(StaticLinkList list,  int i, char *name){
    
    
    
    
    //1、最后位置插入
    int location = Malloc_SLL(list);
   
    
    int k,j,l;
    
    k = MAXSIZE -1;
    if (i < 1 || i > ListLength(list) + 1) {
        return ERROR;
    }
    
    j = location;
    if (j) {
        list[j].name = name;
        
        for (l = 1; l < i; l++){
            k = list[k].cur;
        }
        list[j].cur = list[k].cur;
        list[k].cur = j;
        return OK;
        
        
    }
    return ERROR;
}

void statciLinkListTest(){
   
    StaticLinkList  list;
    
    InitList(list);
    
    
    //list[1].cur = 2;
    list[1].name = "甲";
    
    //list[2].cur = 3;
    list[2].name = "乙";
    
    //list[3].cur = 4;
    list[3].name = "丁";
    
    //list[4].cur = 5;
    list[4].name = "戊";
    
    
    //list[5].cur = 6;
    list[5].name = "己";
    
    //下一个为空 cur 指向0
    list[6].cur = 0;
    list[6].name = "庚";
    
    //头指针指向下一个空元素位置
    list[0].cur = 7;
    list[MAXSIZE - 1].cur = 1;
    
   

//    for (int i = 1; i < 7; i++) {
//       printf("%d --- %s,",list[i].cur,list[i].name);
//    }
    
    
    
    
    
     //插入一个数据
    ListInsert(list, 3, "丙");
//    ListInsert(list, 3, "A");
//    ListInsert(list, 3, "B");
    
     ListDelete(list, 1);
    
    for (int i = 0; i <= ListLength(list); i++) {
        printf("%d --- %s,",list[i].cur,list[i].name);
    }
    
    
}




