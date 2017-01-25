//
//  NoramlStringIndexCaculator.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/1/13.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "NoramlStringIndexCaculator.h"

#define Main_size 7
#define Sub_size 3

int normalStringIndexFinder(char *mainString, char *subString, int pos){
    
    //Xbadgooc, "Xooc"
    // ooc
    int i = pos;
    int j = 1;
    
    while (i <= Main_size && j <= Sub_size) {
        
        if (j == 0 || mainString[i] == subString[j]) {
            ++j;
            ++i;
        }else{
            //i = 2 j= 1
            i = i - j + 2;
            j = 1;
        }
        
    }
    
    if (j > Sub_size) {
        return i - Sub_size;
    }
    
    return 0;
}

void printNoramlStringIndex(){

    printf("查找子位置%d\n",normalStringIndexFinder("Xbadgooc","Xooc",2));
}