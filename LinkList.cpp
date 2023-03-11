// Created by XiaoYu on 2023/3/6.
#include "function.h"
void LinkList_head_insert(LinkList &L){
    L=(LinkList) malloc(sizeof(LNode));
    L->next=NULL;
    ElemType x;
    scanf("%d",&x);
    LinkList s;
    while (x!=9999){
        s=(LinkList) malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
}

void Print_LinkList(LinkList L){
    L=L->next;
    while (L!=NULL){
        printf("%3d",L->data);
        L=L->next;
    }
    printf("\n");
}

void LinkList_tail_insert(LinkList &L){
    L=(LinkList) malloc(sizeof(LNode));
    L->next=NULL;
    ElemType x;
    scanf("%d",&x);
    LinkList s,r=L;
    while (x!=9999){
        s=(LinkList) malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
}

LinkList LinkList_local_search(LinkList L,ElemType local){
    if (local<0){
        return NULL;
    }
    int j=0;
    while (L&&j<local){
        L=L->next;
        j++;
    }
    return L;
}

LinkList LinkList_elem_search(LinkList L,ElemType elem){
    while (L){
        if (L->data==elem){
            return L;
        }
        L=L->next;
    }
    return NULL;
}

bool LinkList_local_insert(LinkList &L,ElemType local,ElemType elem){
    LinkList p= LinkList_local_search(L,local-1);
    if (p==NULL){
        return false;
    }
    LinkList q=(LinkList) malloc(sizeof(LNode));
    q->data=elem;
    q->next=p->next;
    p->next=q;
    return true;
}

bool LinkList_local_del(LinkList &L,ElemType local){
    LinkList p= LinkList_local_search(L,local-1);
    if (p==NULL){
        return false;
    }
    LinkList q=p->next;
    p->next=q->next;
    free(q);
    return true;
}

//    //头插法
//    LinkList L;
//    LinkList_head_insert(L);
//    printf("Head insert:\n");
//    Print_LinkList(L);

//    //尾插法
//    LinkList_tail_insert(L);
//    printf("Tail insert:\n");
//    Print_LinkList(L);

//    //按位置查找
//    L=LinkList_local_search(L,2);
//    printf("Local_search:%d\n",L->data);
//
//    //按值查找
//    L= LinkList_elem_search(L,3);
//    if (L!=NULL){
//        printf("Already find!\n");
//    } else{
//        printf("Not find!\n");
//    }

//    //按位置插入
//    LinkList_local_insert(L,3,99);
//    Print_LinkList(L);