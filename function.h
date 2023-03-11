// Created by XiaoYu on 2023/3/3.

#ifndef PRACTICE_FUNCTION_H
#define PRACTICE_FUNCTION_H
#include <cstdlib>
#include <cstdio>

#define MaxSize 50

typedef int ElemType;
typedef char TElemType;;

//顺序表结构
typedef struct {
    ElemType data[MaxSize];
    ElemType len;
}SqList;

//链表结构
typedef struct LNode{
    ElemType data;
    struct LNode* next;
}LNode,*LinkList;

//栈结构
typedef struct {
    ElemType data[MaxSize];
    int top;
}Stack;

//队列结构
typedef struct LinkQ{
    ElemType data;
    struct LinkQ* next;
}LinkQ;
//辅助队列
typedef struct {
    LinkQ *front,*rear;
}Link_Queue;

//二叉树结构
typedef struct Tree{
    TElemType c;
    struct Tree* lchild;
    struct Tree* rchild;
}Tree,*BTree;
typedef struct tag{
    BTree p;
    struct tag* pnext;
}tag,*Btag;
//层序遍历需要
typedef BTree ElemType1;

//层序遍历队列结构
typedef struct Tree_LinkQ{
    ElemType1 data;
    struct Tree_LinkQ* next;
}Tree_LinkQ;
//辅助队列
typedef struct {
    Tree_LinkQ *front,*rear;
}Tree_Link_Queue;


//顺序表函数
bool SqList_insert(SqList &L,ElemType local,ElemType ele);
void Print_SqList(SqList L);
bool SqList_del(SqList &L,ElemType local,ElemType &x);
int SqList_search(SqList L,ElemType ele);
int SqList_Get(SqList &L,ElemType local);

//链表函数
void LinkList_head_insert(LinkList &L);
void Print_LinkList(LinkList L);
void LinkList_tail_insert(LinkList &L);
LinkList LinkList_local_search(LinkList L,ElemType local);
LinkList LinkList_elem_search(LinkList L,ElemType elem);
bool LinkList_local_insert(LinkList &L,ElemType local,ElemType elem);
bool LinkList_local_del(LinkList &L,ElemType local);

//栈函数
void Init_Stack(Stack &S);
bool Is_empty_Stack(Stack S);
bool Stack_push(Stack &S,ElemType elem);
void Print_Stack(Stack S);
bool Stack_GetTop(Stack S,ElemType &elem);
bool Stack_out(Stack &S,ElemType &elem);

//链表队列函数
void Init_Queue(Link_Queue &Q);
bool Is_empty_Queue(Link_Queue Q);
bool Queue_in(Link_Queue &Q,ElemType elem);
bool Queue_out(Link_Queue &Q,ElemType &elem);

//二叉树函数
void Tree_in(Tree_Link_Queue &Q,ElemType1 x);
void Tree_PreOrder(BTree p);
void Tree_InOrder(BTree p);
void Tree_TailOrder(BTree p);
void Tree_LevelOrder(BTree T);
bool Tree_isEmpty(Tree_Link_Queue Q);

#endif //PRACTICE_FUNCTION_H
