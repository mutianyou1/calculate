//
//  HashTable.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/3/24.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "HashTable.h"
#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12
#define NULLKEY -32768

typedef int Status;

typedef  struct HashTable {
    int *elem;
    int count;
}HashTable;
int m = 0;//全局变量表长

Status InitHashTable(HashTable *H){
    int i;
    m = HASHSIZE;
    
    H ->count = m;
    
    H ->elem = (int*)malloc(m * sizeof(int));
    for (i = 0; i < m; i++) {
        H->elem[i] = NULLKEY;
    }
    
    return SUCCESS;
}

int Hash(int key){
    return key % m;
}
void insertHash(HashTable *H, int key){
    int addr = Hash(key);
    
    while (H->elem[addr] != NULLKEY) {
        addr = (addr + 1) % m;
        //printf("H.elem[%d] = %d\n",addr,key);
    }
    H ->elem[addr] = key;
    printf("H.elem[%d] = %d\n",addr,key);
}
Status searchHashTable(HashTable H,int key,int *addr){
    *addr = Hash(key);
    while (H.elem[*addr] != key) {
        *addr = (*addr + 1) % m;
         printf("-----:%d\n",*addr);
        if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) {
            return SUCCESS;
        }
       
    }
    
    
    return SUCCESS;
}
void hashTable(){
    HashTable H;
    int a[12] = {12,67,56,16,25,37,22,29,15,47,48,34};
    InitHashTable(&H);
    
    for (int i = 0; i < HASHSIZE; i++) {
        insertHash(&H, a[i]);
    }
    

    int result = -1;
    searchHashTable(H, 74, &result);
    printf("result:%d\n",result);
}