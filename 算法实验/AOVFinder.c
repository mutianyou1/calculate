//
//  AOVFinder.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/3/17.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "AOVFinder.h"
#include "Header.h"

#define Maxsize 14
typedef  int Subs[Maxsize][Maxsize];

int *etv, *ltv;
int *stack_;
int top_;

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


typedef VertexNode Nodes[Maxsize][Maxsize];

int topLogicalSort(GraphAdjList GL){
    EdgeNode *edge;
    int k ,i,gettop;
    
    int top = 0;
    int count = 0;
    
    
    int *stack;
    //(int*)malloc(list->numVertexex * sizeof(int))
    stack = (int*)malloc(GL->numVertexex * sizeof(int));
    //入度为0的存入栈中
    for ( i = 0; i < GL -> numVertexex; i++) {
        if (GL ->adjList[i].in == 0) {
            stack[++top] = i;
        }
    }
    //0-1-3 
    while (top != 0) {
        gettop = stack[top--];
        //打印顶点
        /*
         
         count:1
         print:3-1-
         13.in = 1
         2.in = 0
         4.in = 1
         8.in = 1
         7.in = 1
         5.in = 2
         stack[0-1-2]
         */
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
void setSubs(Subs S){
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 14; j++) {
            S[i][j] =  100;
        }
    }
}

int topLogicalSortForCritical(GraphAdjList list){
    EdgeNode *node;
    int i,k,gettop;
    int top = 0;
    int count = 0;
    
    int *stack;
    
    
    stack = (int*)malloc(list->numVertexex * sizeof(int));
    for (i = 0; i < list ->numVertexex; i++) {
        if (list->adjList[i].in == 0) {
            stack[++top] = i;
        }
    }
    
    top_ = 0;
    etv = (int*)malloc(list->numVertexex * sizeof(int));
    for (i = 0; i < list->numVertexex; i++) {
        etv[i] = 0;
    }
    stack_ = (int*)malloc(list->numVertexex * sizeof(int));
    
    while (top != 0) {
        gettop = stack[top--];
        stack_[++top_] = gettop;
        count ++;
        
        for (node = list->adjList[gettop].firstEdge; node;node =  node->next) {
            k = node->adjvex;
            if (!(--list->adjList[k].in)) {
                stack[++top] = k;
            }
            //最早开始时间 取节点各个入点的最大值
            if (etv[gettop] + node ->weight > etv[k]) {
                etv[k] = etv[gettop] + node ->weight;
            }
        }
        
        
    }
    if (count < list->numVertexex) {
        return 0;
    }else {
        return 1;
    }
    
    return 0;
}

void findCriticalPath(GraphAdjList list){
    EdgeNode *node;
    int i,gettop,k,j;
    int ete,lte;
    topLogicalSortForCritical(list);
    ltv = (int*)malloc(list ->numVertexex *(sizeof(int)));
    
    //evt =    [0,3,4,12,15,11,24,19,24,27]
    //ltv =    [27,27,27,27,27,27,27,27,27];
    //stack_ = [0,0,1,2,3,4,6,5,7,8,9];
    //top_ =   10;
    
    for (i = 0; i < list ->numVertexex; i++) {
        ltv[i] = etv[list->numVertexex - 1];
    }
    while (top_ != 0) {
        gettop = stack_[top_--];//1
        for (node = list ->adjList[gettop].firstEdge; node; node = node->next) {
            k = node ->adjvex;//3 8
            //ltv =    [0,7,4,12,15,13,25,19,24,27];
            //取入点最小值最早执行
            if (ltv[k] - node ->weight < ltv[gettop]) {
                ltv[gettop] = ltv[k] - node ->weight;
            }
        }
    }
    //evt =    [0,3,4,12,15,11,24,19,24,27]
    //ltv =    [0,7,4,12,15,13,25,19,24,27];
    //stack_ = [0,1,2,3,4,6,5,7,8,9];
    //top_ =    0;
    for (j = 0 ; j < list ->numVertexex; j++) {
        for (node = list ->adjList[j].firstEdge; node; node = node ->next) {
            k = node -> adjvex;
            ete = etv[j];
            lte = ltv[k] - node->weight;
            //如果最早等于最晚那就是关键路径
            if (ete == lte) {
                printf("<v%d,v%d> length : %d\n",list->adjList[j].data,list->adjList[k].data,node->weight);
            }
        }
    }


}
void setNodes(GraphAdjList list,int index, int in,VertexNode *vertx,EdgeNode *node1,EdgeNode *node2,EdgeNode *node3,int int1,int int2,int int3){
    vertx->in = in;
    vertx->data = index;
    if (int1 < 100) {
        node1->adjvex = int1;
        vertx->firstEdge = node1;
    }
    if (int2 < 100) {
        node2->adjvex = int2;
        node1->next = node2;
    }
    if (int3 < 100) {
        node3->adjvex = int3;
        node2->next = node3;
    }
   list->adjList[index] = *vertx;

}
void aovFinder(){
    graphAdjList list;
    list.numVertexex = 14;
   
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
    setSubs(subs);
    subs[0][0] = 11;
    subs[0][1] = 5;
    subs[0][2] = 4;
    
    subs[1][0] = 8;
    subs[1][1] = 4;
    subs[1][2] = 2;
    
    subs[2][0] = 9;
    subs[2][1] = 6;
    subs[2][2] = 5;
    
    subs[3][0] = 13;
    subs[3][1] = 2;
    subs[3][2] = 100;
    
    subs[4][0] = 7;
    subs[4][1] = 100;
    subs[4][2] = 100;
    
    subs[5][0] = 12;
    subs[5][1] = 8;
    subs[5][2] = 100;
    
    subs[6][0] = 5;
    subs[6][1] = 100;
    subs[6][2] = 100;
    
    subs[8][0] = 7;
    subs[8][1] = 100;
    subs[8][2] = 100;
    
    subs[9][0] = 11;
    subs[9][1] = 10;
    subs[9][2] = 100;
    
    subs[10][0] = 13;
    subs[10][1] = 100;
    subs[10][2] = 100;
    
    subs[12][0] = 9;
    subs[12][1] = 100;
    subs[12][2] = 100;
    
 
    VertexNode node0;
    EdgeNode node0_0;
    EdgeNode node0_1;
    EdgeNode node0_2;
    setNodes(&list,0,ins[0],&node0,&node0_0,&node0_1,&node0_2,subs[0][0],subs[0][1], subs[0][2]);
    
    

    VertexNode node1;
    EdgeNode node1_0;
    EdgeNode node1_1;
    EdgeNode node1_2;
    setNodes(&list,1,ins[1],&node1,&node1_0,&node1_1,&node1_2,subs[1][0],subs[1][1], subs[1][2]);
    
    VertexNode node2;
    EdgeNode node2_0;
    EdgeNode node2_1;
    EdgeNode node2_2;
    setNodes(&list,2,ins[2],&node2,&node2_0,&node2_1,&node2_2,subs[2][0],subs[2][1], subs[2][2]);
    
    VertexNode node3;
    EdgeNode node3_0;
    EdgeNode node3_1;
    EdgeNode node3_2;
    setNodes(&list,3,ins[3],&node3,&node3_0,&node3_1,&node3_2,subs[3][0],subs[3][1], subs[3][2]);
    
    VertexNode node4;
    EdgeNode node4_0;
    EdgeNode node4_1;
    EdgeNode node4_2;
    setNodes(&list,4,ins[4],&node4,&node4_0,&node4_1,&node4_2,subs[4][0],subs[4][1], subs[4][2]);
    
    VertexNode node5;
    EdgeNode node5_0;
    EdgeNode node5_1;
    EdgeNode node5_2;
    setNodes(&list,5,ins[5],&node5,&node5_0,&node5_1,&node5_2,subs[5][0],subs[5][1], subs[5][2]);
    
    VertexNode node6;
    EdgeNode node6_0;
    EdgeNode node6_1;
    EdgeNode node6_2;
    setNodes(&list,6,ins[6],&node6,&node6_0,&node6_1,&node6_2,subs[6][0],subs[6][1], subs[6][2]);
    
    VertexNode node7;
    EdgeNode node7_0;
    EdgeNode node7_1;
    EdgeNode node7_2;
    setNodes(&list,7,ins[7],&node7,&node7_0,&node7_1,&node7_2,subs[7][0],subs[7][1], subs[7][2]);
    
    VertexNode node8;
    EdgeNode node8_0;
    EdgeNode node8_1;
    EdgeNode node8_2;
    setNodes(&list,8,ins[8],&node8,&node8_0,&node8_1,&node8_2,subs[8][0],subs[8][1], subs[8][2]);
    
    VertexNode node9;
    EdgeNode node9_0;
    EdgeNode node9_1;
    EdgeNode node9_2;
    setNodes(&list,9,ins[9],&node9,&node9_0,&node9_1,&node9_2,subs[9][0],subs[9][1], subs[9][2]);
    
    VertexNode node10;
    EdgeNode node10_0;
    EdgeNode node10_1;
    EdgeNode node10_2;
    setNodes(&list,10,ins[10],&node10,&node10_0,&node10_1,&node10_2,subs[10][0],subs[10][1], subs[10][2]);
    
    VertexNode node11;
    EdgeNode node11_0;
    EdgeNode node11_1;
    EdgeNode node11_2;
    setNodes(&list,11,ins[11],&node11,&node11_0,&node11_1,&node11_2,subs[11][0],subs[11][1], subs[11][2]);
    
    VertexNode node12;
    EdgeNode node12_0;
    EdgeNode node12_1;
    EdgeNode node12_2;
    setNodes(&list,12,ins[12],&node12,&node12_0,&node12_1,&node12_2,subs[12][0],subs[12][1], subs[12][2]);
    
    VertexNode node13;
    EdgeNode node13_0;
    EdgeNode node13_1;
    EdgeNode node13_2;
    
    setNodes(&list,13,ins[13],&node13,&node13_0,&node13_1,&node13_2,subs[13][0],subs[13][1], subs[13][2]);
    
    
    
    topLogicalSort(&list);
    printf("\n");
    
}
void aovFindCriticalPath(){
    graphAdjList list;
    list.numVertexex = 10;
    
    int ins[10];
    ins[0] = 0;
    ins[1] = 1;
    ins[2] = 1;
    ins[3] = 2;
    ins[4] = 2;
    ins[5] = 1;
    ins[6] = 1;
    ins[7] = 2;
    ins[8] = 1;
    ins[9] = 2;
    
    
    Subs subs;
    setSubs(subs);
    subs[0][0] = 2;
    subs[0][1] = 1;

    
    subs[1][0] = 4;
    subs[1][1] = 3;

    
    subs[2][0] = 5;
    subs[2][1] = 3;

    
    subs[3][0] = 4;
  

    
    subs[4][0] = 7;
    subs[4][1] = 6;

    
    subs[5][0] = 7;
   
    
    subs[6][0] = 9;
    
    subs[7][0] = 8;
    
    subs[8][0] = 9;
   
    
    
    
    
    VertexNode node0;
    EdgeNode node0_0;
    EdgeNode node0_1;
    EdgeNode node0_2;
    node0_0.weight = 4;
    node0_1.weight = 3;
    node0_2.weight = 0;
    setNodes(&list,0,ins[0],&node0,&node0_0,&node0_1,&node0_2,subs[0][0],subs[0][1], subs[0][2]);
    
    
    
    VertexNode node1;
    EdgeNode node1_0;
    EdgeNode node1_1;
    EdgeNode node1_2;
    node1_0.weight = 6;
    node1_1.weight = 5;
    node1_2.weight = 0;
    setNodes(&list,1,ins[1],&node1,&node1_0,&node1_1,&node1_2,subs[1][0],subs[1][1], subs[1][2]);
    
    VertexNode node2;
    EdgeNode node2_0;
    EdgeNode node2_1;
    EdgeNode node2_2;
    node2_0.weight = 7;
    node2_1.weight = 8;
    node2_2.weight = 0;
    setNodes(&list,2,ins[2],&node2,&node2_0,&node2_1,&node2_2,subs[2][0],subs[2][1], subs[2][2]);
    
    VertexNode node3;
    EdgeNode node3_0;
    EdgeNode node3_1;
    EdgeNode node3_2;
    node3_0.weight = 3;
    node3_1.weight = 0;
    node3_2.weight = 0;
    setNodes(&list,3,ins[3],&node3,&node3_0,&node3_1,&node3_2,subs[3][0],subs[3][1], subs[3][2]);
    
    VertexNode node4;
    EdgeNode node4_0;
    EdgeNode node4_1;
    EdgeNode node4_2;
    node4_0.weight = 4;
    node4_1.weight = 9;
    node4_2.weight = 0;
    setNodes(&list,4,ins[4],&node4,&node4_0,&node4_1,&node4_2,subs[4][0],subs[4][1], subs[4][2]);
    
    VertexNode node5;
    EdgeNode node5_0;
    EdgeNode node5_1;
    EdgeNode node5_2;
    node5_0.weight = 6;
    node5_1.weight = 0;
    node5_2.weight = 0;
    setNodes(&list,5,ins[5],&node5,&node5_0,&node5_1,&node5_2,subs[5][0],subs[5][1], subs[5][2]);
    
    VertexNode node6;
    EdgeNode node6_0;
    EdgeNode node6_1;
    EdgeNode node6_2;
    node6_0.weight = 2;
    node6_1.weight = 0;
    node6_2.weight = 0;
    setNodes(&list,6,ins[6],&node6,&node6_0,&node6_1,&node6_2,subs[6][0],subs[6][1], subs[6][2]);
    
    VertexNode node7;
    EdgeNode node7_0;
    EdgeNode node7_1;
    EdgeNode node7_2;
    node7_0.weight = 5;
    node7_1.weight = 0;
    node7_2.weight = 0;
    setNodes(&list,7,ins[7],&node7,&node7_0,&node7_1,&node7_2,subs[7][0],subs[7][1], subs[7][2]);
    
    VertexNode node8;
    EdgeNode node8_0;
    EdgeNode node8_1;
    EdgeNode node8_2;
    node8_0.weight = 3;
    node8_1.weight = 0;
    node8_2.weight = 0;
    setNodes(&list,8,ins[8],&node8,&node8_0,&node8_1,&node8_2,subs[8][0],subs[8][1], subs[8][2]);
    
    VertexNode node9;
    EdgeNode node9_0;
    EdgeNode node9_1;
    EdgeNode node9_2;
    node9_0.weight = 0;
    node9_1.weight = 0;
    node9_2.weight = 0;
    setNodes(&list,9,ins[9],&node9,&node9_0,&node9_1,&node9_2,subs[9][0],subs[9][1], subs[9][2]);
    
    
    
    
    
    findCriticalPath(&list);



}