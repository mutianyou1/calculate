//
//  main.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/1/11.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include <stdio.h>
#include "StaticLinkList.h"
#include "KMP.h"
#include "FeboNaYe.h"
#include "BitTree.h"
#include "NoramlStringIndexCaculator.h"
#include "Kruskal.h"
#include "Dijkstra.h"
#include "Floyd.h"
#include "AOVFinder.h"
int main(int argc, const char * argv[]) {
   
    //statciLinkListTest();
    //printFeboNaYe();
    //printKMPNextArray();
    //printNoramlStringIndex();
   // printBitTree();
    //kruskalFindMinTree();
    //DijkstraShortPath();
    FloydFindShortWay();
    //aovFinder();
    return 0;
}
