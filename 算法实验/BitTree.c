//
//  BitTree.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/1/19.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "BitTree.h"

typedef struct BitNode{
  
    struct BitNode *lChild;
    struct BitNode *rChild;
    char data;
    
}BitNode,*BitTree;

void createBitTree(BitTree *T){
    char data;
    scanf("%c",&data);
    
    if (data == '#') {
        *T = NULL;
    }else{
        *T = (BitTree)malloc(sizeof(BitNode));
        if (!*T) {
            return;
        }
        
        (*T) -> data = data;
        createBitTree(&(*T) -> lChild);
        createBitTree(&(*T) -> rChild);
    }
    
    
    
}

void printBitTree(){
    
    BitTree T;
    createBitTree(&T);

}