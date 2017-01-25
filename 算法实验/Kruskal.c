//
//  Kruskal.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/1/25.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "Kruskal.h"

#define OK 1
#define ERROE 0
#define TRUE 1
#define FALSE 0

typedef int Status;

#define MAXEDGE 20
#define MAXVEX 20
#define INFINITY 5595


typedef struct{
    int arc[MAXVEX][MAXVEX];
    int numVertextes,numEdges;
    char data[MAXVEX];
}MGraph;


typedef struct {
    int weight , begin, end;
}Edge;


void creatMGraph(MGraph *G){
    int i,j;
    //15 条边 9个点
    G->numEdges = 15;
    G->numVertextes = 9;
    
    //init
    for (i = 0; i < G->numVertextes; i++) {
        for (j = 0; j < G->numVertextes; j++) {
            if (i == j) {
                G ->arc[i][j] = 0;
            }else{
                G ->arc[i][j] = G ->arc[j][i] = INFINITY;
            }
        }
    }
    
      G ->arc[0][1] = 10;
      G ->arc[0][5] = 11;
      G ->arc[1][2] = 18;
      G ->arc[1][8] = 12;
      G ->arc[1][6] = 16;
      G ->arc[2][8] = 8;
      G ->arc[2][3] = 22;
      G ->arc[3][8] = 21;
      G ->arc[3][6] = 24;
      G ->arc[3][7] = 16;
      G ->arc[3][4] = 20;
      G ->arc[4][7] = 7;
      G ->arc[4][5] = 26;
      G ->arc[5][6] = 17;
      G ->arc[6][7] = 19;
    
      G ->data[0] = 'A';
      G ->data[1] = 'B';
      G ->data[2] = 'C';
      G ->data[3] = 'D';
      G ->data[4] = 'E';
      G ->data[5] = 'F';
      G ->data[6] = 'G';
      G ->data[7] = 'H';
      G ->data[8] = 'I';
    
    
    
    
    
    
    
    //等线向交换
    for (i = 0; i < G ->numVertextes; i++) {
        for (j = i; j < G->numVertextes; j++) {
             G->arc[j][i] = G->arc[i][j];
        }
    }
    
}

void swap(Edge *edge , int i ,int j){
    int temp;
    temp = edge[i].begin;
    edge[i].begin = edge[j].begin;
    edge[j].begin = temp;
    
    temp = edge[i].end;
    edge[i].end = edge[j].end;
    edge[j].end = temp;
    
    temp = edge[i].weight;
    edge[i].weight = edge[j].weight;
    edge[j].weight = temp;
}

void sort(Edge edge[] ,MGraph *G){
    int i,j;
    
    for (i = 0; i < G ->numEdges; i++) {
        
        for (j = i + 1; j < G->numEdges; j++) {
            if (edge[i].weight > edge[j].weight) {
                swap(edge, i, j);
            }
            
        }
    }
    
    for (i = 0; i < G ->numEdges; i++) {
        printf("(%d %d) %d\n",edge[i].begin,edge[i].end,edge[i].weight);
    }
   
}


int find(int *parent , int f){
    while(parent[f] > 0) {
        f = parent[f];
    }
    return f;
}
void MinTree(MGraph G){
    int i,j,n,m,k;
    k = 0;
    int  parent[MAXVEX];
    Edge edges[MAXEDGE];
    
    
    for (i = 0; i < G.numVertextes; i++) {
        for (j = i+1; j < G.numVertextes; j++) {
            if (G.arc[i][j] < INFINITY) {
                 edges[k].begin = i;
                 edges[k].end = j;
                 edges[k].weight = G.arc[i][j];
                 k ++;
            }
           
        }
    }
    
    sort(edges, &G);
    
    for (i = 0; i < G.numVertextes; i++) {
        parent[i] = 0;
    }
    
    printf("开始查询最小生成树\n");
    
    int sum = 0;
    for (i = 0; i < G.numEdges; i++) {
        n = find(parent, edges[i].begin);
        m = find(parent, edges[i].end);
        if (n != m) {
            parent[n] = m;
            sum += edges[i].weight;
            printf("产生(%d %d)  %d -- %c\n",edges[i].begin,edges[i].end,edges[i].weight,G.data[edges[i].begin]);
        }
    }
    printf("sum = %d\n",sum);
}
void kruskalFindMinTree(){
    MGraph G;
    creatMGraph(&G);
    MinTree(G);
}