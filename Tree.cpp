// Created by XiaoYu on 2023/3/6.
#include "function.h"
void Tree_PreOrder(BTree p){
    if (p!=NULL){

        putchar(p->c);
        Tree_PreOrder( p->lchild);
        Tree_PreOrder( p->rchild);
    }

}

void Tree_InOrder(BTree p){
    if (p!=NULL){

        Tree_InOrder( p->lchild);
        putchar(p->c);
        Tree_InOrder( p->rchild);
    }

}

void Tree_TailOrder(BTree p){
    if (p!=NULL){

        Tree_TailOrder( p->lchild);
        Tree_TailOrder( p->rchild);
        putchar(p->c);
    }

}

void Init_TreeQueue(Tree_Link_Queue &Q){

Q.front=Q.rear=(Tree_LinkQ*) malloc(sizeof(Tree_LinkQ));
Q.front->next=NULL;
}

void Tree_in(Tree_Link_Queue &Q,ElemType1 x){
    Tree_LinkQ *s=(Tree_LinkQ *) malloc(sizeof (Tree_LinkQ));
    s->data=x;
    s->next=NULL;
    Q.rear->next=s;
    Q.rear=s;
}

bool Tree_isEmpty(Tree_Link_Queue Q){
    if (Q.front==Q.rear){
        return true;
    }
}

bool Tree_out(Tree_Link_Queue &Q,ElemType1 &x){
    if (Q.rear==Q.front){
        return false;
    }
    Tree_LinkQ *p=Q.front->next;
    x=p->data;
    Q.front->next=p->next;
    if (Q.rear==p){
        Q.rear=Q.front;
    }
    free(p);
    return true;
}

void Tree_LevelOrder(BTree T) {
    Tree_Link_Queue Q;
    Init_TreeQueue(Q);
    BTree p;
    Tree_in(Q, T);
    while (!Tree_isEmpty(Q)) {
        Tree_out(Q, p);
        putchar(p->c);
        if (p->lchild != NULL) {
            Tree_in(Q, p->lchild);
        }
        if (p->rchild != NULL) {
            Tree_in(Q, p->rchild);
        }
    }
}

//BTree pnew;
//char c;
//BTree tree=NULL;
//Btag head=NULL,tail=NULL,pcur=NULL,listnew=NULL;
//while (scanf("%c",&c)){
//if (c=='\n'){
//break;
//}
//pnew=(BTree) calloc(1, sizeof(Tree));
//pnew->c=c;
//listnew=(Btag) calloc(1, sizeof(tag));
//listnew->p=pnew;
//if (tree==NULL){
//tree=pnew;
//head=listnew;
//tail=listnew;
//pcur=listnew;
//continue;
//} else{
//tail->pnext=listnew;
//tail=listnew;
//}
//if (pcur->p->lchild==NULL){
//pcur->p->lchild=pnew;
//}else if (pcur->p->rchild==NULL){
//pcur->p->rchild=pnew;
//pcur=pcur->pnext;
//}
//}
//前序遍历
//printf("-------Pre-order traversal--------\n");
//Tree_PreOrder(tree);
//printf("\n");
//中序遍历
//printf("-------In-order traversal--------\n");
//Tree_InOrder(tree);
//printf("\n");
//后序遍历
//printf("-------Post-order traversal--------\n");
//Tree_TailOrder(tree);
//printf("\n");
//层序遍历
//printf("-------Layer-order traversal--------\n");
//Tree_LevelOrder(tree);