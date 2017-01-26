//
//  Header.h
//  算法实验
//
//  Created by 潘元荣(外包) on 17/1/25.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <stdio.h>

#define MAXSIZE 100

typedef struct{
    int arc[MAXSIZE][MAXSIZE];
    int numVertextes,numEdges;
    char data[MAXSIZE];
}MGraph;


typedef struct {
    int weight , begin, end;
}Edge;
#endif /* Header_h */
