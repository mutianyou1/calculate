//
//  Dijkstra.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/1/25.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "Dijkstra.h"
#include "Header.h"

#define MAXVEX 9
#define INFINITY_ 5595

typedef int  Pathmatirx[MAXVEX];
typedef int  ShortPathTable[MAXVEX];

void creatMGraph_D(MGraph *G){
    int i,j;
    //15 条边 9个点
   // G->numEdges = 15;
    G->numVertextes = 9;
    
    //init
    for (i = 0; i < G->numVertextes; i++) {
        for (j = 0; j < G->numVertextes; j++) {
            if (i == j) {
                G ->arc[i][j] = 0;
            }else{
                G ->arc[i][j] = G ->arc[j][i] = INFINITY_;
            }
        }
    }
    
    G ->arc[0][1] = 1;
    G ->arc[0][2] = 5;
    G ->arc[1][3] = 7;
    G ->arc[2][5] = 7;
    G ->arc[3][6] = 3;
    G ->arc[6][8] = 7;
    G ->arc[8][7] = 4;
    G ->arc[5][7] = 5;
    G ->arc[1][2] = 3;
    G ->arc[6][7] = 2;
    G ->arc[3][4] = 2;
    G ->arc[4][5] = 3;
    G ->arc[1][4] = 5;
    G ->arc[4][6] = 6;
    G ->arc[2][4] = 1;
    G ->arc[4][7] = 9;

    
    //等线向交换
    for (i = 0; i < G ->numVertextes; i++) {
        for (j = i; j < G->numVertextes; j++) {
            G->arc[j][i] = G->arc[i][j];
        }
    }
    
}


void shorestPath_Dijkstra(MGraph G,int v0, Pathmatirx P,ShortPathTable D){

    int v,k = 0,w,min = 0;
    int final[MAXVEX];
    
    //init
    for (v = 0; v < G.numVertextes; v++) {
        final[v] = 0;
        D[v] = G.arc[v0][v];
        P[v] = 0;
    }
    
    
    D[v0] = 0;
    final[v0] = 1;
    
    //开始主循环
    for (v = 1; v < G.numVertextes; v++) {
        
        min = INFINITY_;
        
        //节点最小
        for (w = 0; w < G.numVertextes; w++) {
            
            if (!final[w] && D[w] < min) {
                k = w;
                min = D[w];
            }
            
        }
        
        //final[k] 做节点判断!final[w]
        final[k] = 1;
         //路径累加
        for (w = 0; w < G.numVertextes; w++) {
            if (!final[w] && (min + G.arc[k][w]) < D[w]) {
                D[w] = min + G.arc[k][w];
                P[w] = k;
                printf("(找到最小)%d\n",D[w]);
            }
        }
        
    }
    
    printf("min %d\n",min);
    
}


void DijkstraShortPath(){
    
    MGraph G;
    creatMGraph_D(&G);
    Pathmatirx p;
    ShortPathTable d;
    shorestPath_Dijkstra(G, 0, p, d);
    
    
}