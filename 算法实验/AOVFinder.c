//
//  AOVFinder.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/3/17.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "AOVFinder.h"
#include "Header.h"

#define Maxsize 13
typedef  int Subs[Maxsize][Maxsize];

typedef struct EdgeNode{
    int adjvex;
    int weight;
    struct EdgeNode *next;
}EdgeNode;


typedef struct VertexNode{
    int in;
    int data;
    EdgeNode *firstEdge;
}VertexNode,AdjList[MAXSIZE];



typedef struct {
    AdjList adjList;
    int numVertexex,numEdges;
}graphAdjList,*GraphAdjList;


int topLogicalSort(GraphAdjList GL){
    EdgeNode *edge;
    int k ,i,gettop;
    
    int top = 0;
    int count = 0;
    
    
    int *stack;
    
    stack = (int*)malloc(GL ->numVertexex * sizeof(int));
    //入度为0的存入栈中
    for ( i = 0; i < GL -> numVertexex; i++) {
        if (GL ->adjList[i].in == 0) {
            stack[++top] = i;
        }
    }
    while (top != 0) {
        gettop = stack[top--];
        //打印顶点
        //3--0--
        printf("%d->",GL->adjList[gettop].data);
        count++;
        
        for (edge = GL ->adjList[gettop].firstEdge; edge; edge = edge->next) {
            k = edge ->adjvex;
            if (!(--GL->adjList[k].in)) {
                stack[++top] = k;
            }
        }
    }
    if (count< GL ->numVertexex) {
        return 0;
    }else{
        return 1;
    }
    
    
    return 0;
}
void setSubs(Subs subs){
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            subs[i][j] =  100;
        }
    }
}
void aovFinder(){
    GraphAdjList list;
    list -> numVertexex = 14;
   
    int ins[14];
    ins[0] = 0;
    ins[1] = 0;
    ins[2] = 2;
    ins[3] = 0;
    ins[4] = 2;
    ins[5] = 3;
    ins[6] = 1;
    ins[7] = 2;
    ins[8] = 2;
    ins[9] = 1;
    ins[10] = 1;
    ins[11] = 2;
    ins[12] = 1;
    ins[13] = 2;
    
    Subs subs;
  
//    for (int i = 0; i < 13; i++) {
//        for (int j = 0; j < 3; j++) {
//            subs[i][j] =  100;
//        }
//    }
    //setSubs(subs);
//    subs[0][0] = 11;
//    subs[0][1] = 5;
//    subs[0][2] = 4;
//    
//    subs[1][0] = 8;
//    subs[1][1] = 4;
//    subs[1][2] = 2;
//    
//    subs[2][0] = 9;
//    subs[2][1] = 6;
//    subs[2][2] = 5;
//    
//    subs[3][0] = 13;
//    subs[3][1] = 2;
//    subs[3][2] = 100;
//    
//    subs[4][0] = 7;
//    subs[4][1] = 100;
//    subs[4][2] = 100;
//    
//    subs[5][0] = 12;
//    subs[5][1] = 8;
//    subs[5][2] = 100;
//    
//    subs[6][0] = 5;
//    subs[6][1] = 100;
//    subs[6][2] = 100;
//    
//    subs[8][0] = 7;
//    subs[8][1] = 100;
//    subs[8][2] = 100;
//    
//    subs[9][0] = 11;
//    subs[9][1] = 10;
//    subs[9][2] = 100;
//    
//    subs[10][0] = 13;
//    subs[10][1] = 100;
//    subs[10][2] = 100;
//    
//    subs[12][0] = 9;
//    subs[12][1] = 100;
//    subs[12][2] = 100;
//    
//    printf("hehie%d",subs[12][2]);
//    for (int i = 0; i < 14; i++) {
//        
//        
//        VertexNode vertex;
//        vertex.in = ins[i];
//        list->adjList[i] = vertex;
//        
//        
//        if (i != 7) {
//            
//            if (i != 11 || i != 12) {
//                EdgeNode node1;
//                node1.adjvex = subs[i][0];
//                
//                if (node1.adjvex < 80) {
//                    vertex.firstEdge = &node1;
//                }
//                
//                EdgeNode node2;
//                node2.adjvex = subs[i][1];
//                
//                if (node2.adjvex < 80) {
//                    node1.next = &node2;
//                }
//                
//                EdgeNode node3;
//                node3.adjvex = subs[i][2];
//                if (node3.adjvex < 80) {
//                    node2.next = &node3;
//                }
//                
//            }
//            
//        }
//        
//    }
    
    //topLogicalSort(list);
    
    
}
