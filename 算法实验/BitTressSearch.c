//
//  BitTressSearch.c
//  算法实验
//
//  Created by 潘元荣(外包) on 17/3/22.
//  Copyright © 2017年 潘元荣(外包). All rights reserved.
//

#include "BitTressSearch.h"
#define LH +1
#define EH 0
#define RH -1



typedef struct BiTNode{
    int data;
    int bf;
    struct BiTNode * lchild,*rchild;
}BiTNode,*BiTree;

int searchBiTress(BiTree T,int key,BiTree f, BiTree *p){
    if (!T) {
        *p = f;
        return 0;
    }else if (key == T ->data){
        *p = T;
        return 1;
    }else if (key > T ->data){
        return searchBiTress(T->rchild,key,T,p);
    }else{
        return searchBiTress(T->lchild,key,T,p);
    }
}
int insertBST(BiTree *T,int key){
    BiTree p,s;
    //p内部结构的节点所以可以直接p->rchild
    if (!searchBiTress(*T, key, NULL, &p)) {
        s = (BiTree)malloc(sizeof(BiTNode));
        s ->data = key;
        s ->lchild = s ->rchild = NULL;
        if (!p) {
            //root node
            *T = s;
        }else if (key > p->data){
           //right child
           p ->rchild = s;
        }else{
           p ->lchild = s;
        }
        return 1;
    }

    return 0;
}
int delete(BiTree *p){
    
    BiTree q,s;
    //一侧子树为空
    if ((*p)->rchild == NULL) {
        q = *p;
        *p = (*q).lchild;
    }else if ((*p)->lchild == NULL){
        q = *p;
        *p = (*q).rchild;
    }else{
      //需要拼接的情况
        q = *p ;
        s = (*p) ->lchild;//35
        while (s->rchild) {
            q = s;//q=35
            s = s ->rchild;//s = 37
        }
        (*p)->data = s ->data;//p->data = 37
        if (q != *p) {
            q ->rchild = s ->lchild;//
        }else{
            q->lchild = s ->lchild;
        }
    
    }
    
    return 1;
}
int deleteBitTress(BiTree *T,int key){
    if (!T) {
        return 0;
    }else{
        if (key == (*T)->data) {
          return   delete(T);
        }else if (key < (*T)->data){
           return deleteBitTress(&(*T)->lchild, key);
        }else{
           return deleteBitTress(&(*T)->rchild, key);
        }
    }
    
    return 0;
}
void R_rotate(BiTree *p){
    BiTree s;
    
    s = (*p)->lchild;
    (*p)->lchild = s->rchild;
    s->rchild = *p;
    *p = s;
}
void L_rotate(BiTree *p){
    BiTree s;
    s = (*p)->rchild;
    (*p)->rchild = s->lchild;
    s->lchild = *p;
    *p = s;
}
//此时跟节点的bf必定>1
void leftBalanceTree(BiTree *T){
    BiTree L,Lr;
    L = (*T)->lchild;
    switch (L->bf) {
        case LH:
            (*T)->bf = L->bf = EH;
            R_rotate(T);
            break;
        case RH:
            //双旋转处理
            Lr = L->rchild;
            switch (Lr ->bf) {
                    //这里的T由于双旋转后不是T所以T后面已经移动位置
                case LH:
                    (*T) ->bf = RH;
                    L->bf = EH;
                    break;
                case RH:
                    (*T)->bf = EH;
                    L->bf = LH;
                    break;
                case EH:
                    (*T)->bf = L->bf =EH;
                    break;
                default:
                    break;
            }
            
            Lr->bf = EH;
            L_rotate(&(*T)->lchild);
            R_rotate(T);
            break;
            
        case EH:
            break;
            
        default:
            break;
    }


}
void rightBalanceTree(BiTree *T){
    BiTree L,Lr;
    L = (*T)->rchild;
    switch (L->bf) {
        case RH:
            (*T)->bf = L->bf = EH;
            L_rotate(T);
            break;
        case LH:
            //双旋转处理
            Lr = L->lchild;
            switch (Lr ->bf) {
                case LH:
                    
                    (*T) ->bf = EH;
                    L->bf = RH;
                    break;
                case RH:
                    (*T)->bf = LH;
                    L->bf = EH;
                    break;
                case EH:
                    (*T)->bf = L->bf =EH;
                    break;
                default:
                    break;
            }
            Lr->bf = EH;
            R_rotate(&(*T)->rchild);
            L_rotate(T);
            
            break;
            
        case EH:
            break;
            
        default:
            break;
    }
}

int insertAVL(BiTree *T,int e,int *status){
    
    if (!*T) {
        //为空插入新的节点
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T)->data = e;
        (*T)->lchild = (*T)->rchild = NULL;
        (*T)->bf = EH;
        *status = 1;
    }else{
       //左子树
        if (e == (*T)->data) {
            *status = 0;
            return *status;
        }else if (e < (*T)->data){
        
            //左子树继续查看是否有对应的数字
            if (!insertAVL(&(*T)->lchild, e, status)) {
                //已存在数据未插入
                *status = 0;
                return *status;
            }
            
            //不存在数据插入成功判断左右平衡bf为之前状态
            if (*status) {
                switch ((*T)->bf) {
                    case EH:
                        (*T)->bf = LH;
                        *status = 1;
                        break;
                    case LH:
                        //原本左子树高左平衡处理
                        leftBalanceTree(T);
                        *status = 0;
                        break;
                    case RH:
                        //原本右子树高一点现在等高
                        (*T)->bf = EH;
                        *status = 0;
                        break;
                    default:
                        break;
                }
            }
        
        
        
        }else{
            if (!insertAVL(&(*T)->rchild, e, status)) {
                *status = 0;
                return *status;
            }
            
            if (*status) {
                switch ((*T)->bf) {
                    case EH:
                        (*T)->bf = RH;
                        *status = 1;
                        break;
                    case LH:
                        //原本左子树高于右子树现在等高
                        (*T)->bf = EH;
                        *status = 0;
                        break;
                        
                    case RH:
                        rightBalanceTree(T);
                        *status = 0;
                        break;
                    default:
                        break;
                }
            }
        
        
        
        }
    
    
    
    }
    
    
    return 1;
}
void bitTressSearch(){

    BiTree T = NULL;
   
    int a[10] = {62,88,58,47,35,73,51,99,37,93};
    for (int i = 0; i < 10; i++) {
        insertBST(&T,a[i]);
    }
//    BiTNode node0;
//    node0.data = 62;
//    
//    BiTNode node1;
//    node1.data = 88;
//    
//    BiTNode node2;
//    node2.data = 58;
//    
//    BiTNode node3;
//    node3.data = 47;
//    
//    BiTNode node4;
//    node4.data = 35;
//    
//    BiTNode node5;
//    node5.data = 73;
//    
//    BiTNode node6;
//    node6.data = 51;
//    
//    BiTNode node7;
//    node7.data = 99;
//    
//    BiTNode node8;
//    node8.data = 37;
//    
//    BiTNode node9;
//    node9.data = 93;
//    
//
//    
//    node0.lchild = &node2;
//    node0.rchild = &node1;
//    
//    
//    node2.lchild = &node3;
//    node3.lchild = &node4;
//    node3.rchild = &node6;
//    
//    node4.rchild = &node8;
//    
//    
//    node1.rchild = &node7;
//    node1.lchild = &node5;
//    
//    node7.lchild = &node9;
//    
//    T = &node0;
//    
    BiTree P;
    int  result = searchBiTress(T,37,NULL,&P);
    printf("status:%d",result);
    if (P != NULL) {
       printf("result:%d\n",P->data);
    }
   
    deleteBitTress(&T, 47);
    
}
void balanceBinarySearch(){
    int i ;
    int a[10] = {3,2,1,4,5,6,7,10,9,8};
    BiTree T = NULL;
    for (int k = 0; k < 10; k++) {
        insertAVL(&T, a[k], &i);
    }
    
    
}