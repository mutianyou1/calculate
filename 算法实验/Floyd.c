//
//  Floyd.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/1/26.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "Floyd.h"
#include "Header.h"


#define MAXVEX 20
#define INFINITY_ 54444
typedef int Pathmatirx[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

void creatMGraph_Floyd(MGraph *G){
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



void shortPathFloyd(MGraph G, Pathmatirx P, ShortPathTable D){
    int v, w,k;
    
    for (v = 0; v < G.numVertextes; v++) {
        
        for (w= 0; w < G.numVertextes; w++) {
             D[v][w] = G.arc[v][w];
             P[v][w] = w;
        }
    }
    
    for (k = 0; k < G.numVertextes; k++) {
        
        for (v = 0; v < G.numVertextes; v++) {
            
            for (w = 0; w < G.numVertextes; w++) {
                if (D[v][w] > D[v][k] + D[k][w]) {
                    D[v][w] = D[v][k] + D[k][w];
                    P[v][w] = P[v][k];
                }
            }
        }
    }
}

void FloydFindShortWay(){
    MGraph G;
    Pathmatirx P;
    ShortPathTable D;
    creatMGraph_Floyd(&G);
    shortPathFloyd(G, P, D);
    
}