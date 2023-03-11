// Created by XiaoYu on 2023/3/6.
#include "function.h"
void Init_Queue(Link_Queue &Q){
    Q.front=Q.rear=(LinkQ*) malloc(sizeof(LinkQ));
    Q.front->next=NULL;
}

bool Is_empty_Queue(Link_Queue Q){
    if (Q.front==Q.rear){
        return true;
    } else{
        return false;
    }
}

bool Queue_in(Link_Queue &Q,ElemType elem){
    LinkQ *s=(LinkQ*) malloc(sizeof (LinkQ));
    s->data=elem;
    s->next=NULL;
    Q.rear->next=s;
    Q.rear=s;
    return true;
}

bool Queue_out(Link_Queue &Q,ElemType &elem){
    if (Q.rear==Q.front){
        return false;
    }
    LinkQ *p=Q.front->next;
    elem=p->data;
    Q.front->next=p->next;
    if (Q.rear==p){
        Q.rear=Q.front;
    }
    free(p);
    return true;
}

//    Link_Queue Q;
//    bool ret;
//    Init_Queue(Q);
//    Is_empty_Queue(Q);
//    Queue_in(Q,1);
//    Queue_in(Q,2);
//    ret=Queue_in(Q,3);
//    if (ret){
//        printf("InQueue success!\n");
//    }
//    ElemType elem;
//    Queue_out(Q,elem);
//    printf("%d out from the Queue\n",elem);

