//
//  FeboNaYe.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/1/11.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "FeboNaYe.h"


int getFeboNaye(int i){
    return i > 2 ? getFeboNaye(i - 1) + getFeboNaye(i - 2) : 1;
}

void printFeboNaYe(){
   
    
    int a[40];
    a[0] = 1;
    a[1] = 1;
    
    for (int i = 0; i < 40; i++) {
        a[i] = getFeboNaye(i);
        printf("boyena%d\n",a[i]);
    }
    
    
 


}