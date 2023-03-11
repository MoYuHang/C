// Created by XiaoYu on 2023/3/6.
#include "function.h"
void Init_Stack(Stack &S){
    S.top=-1;
}

bool Is_empty_Stack(Stack S){
    if (S.top==-1){
        return true;
    } else{
        return false;
    }
}

bool Stack_push(Stack &S,ElemType elem){
    if (S.top==MaxSize-1){
        return false;
    }
    S.data[++S.top]=elem;
    return true;
}

void Print_Stack(Stack S){
    for (int i = 0; i <= S.top; i++) {
        printf("%3d",S.data[i]);
    }
    printf("\n");
}

bool Stack_GetTop(Stack S,ElemType &elem){
    if (S.top==-1){
        return false;
    }
    elem=S.data[S.top];
    return true;
}

bool Stack_out(Stack &S,ElemType &elem){
    if (S.top==-1){
        return false;
    }
    elem=S.data[S.top--];
    return true;
}

//Stack S;
//bool ret;
//Init_Stack_Stack(S);
//ret=Is_empty(S);
//if (ret){
//printf("The Stack is empty!\n");
//}
//Stack_push(S,1);
//Stack_push(S,2);
//Stack_push(S,3);
//Print_Stack(S);
//ElemType elem;
//Stack_GetTop(S,elem);
//printf("Top number is %d\n",elem);
//Stack_out(S,elem);
//printf(" %d was out from the Stack!\n",elem);
//Stack_GetTop(S,elem);
//printf("Top number is %d\n",elem);
