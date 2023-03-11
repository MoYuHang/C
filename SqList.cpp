// Created by XiaoYu on 2023/3/6.
#include "function.h"
bool SqList_insert(SqList &L,ElemType local,ElemType ele){
    if (local<1||local>L.len+1){
        return false;
    }
    if (L.len==MaxSize){
        return false;
    }
    for (int i = L.len; local<=i ; i--) {
        L.data[i]=L.data[i-1];
    }
    L.data[local-1]=ele;
    L.len++;
    return true;
}

void Print_SqList(SqList L){
    for (int i = 0; i < L.len; i++) {
        printf("%3d",L.data[i]);
    }
    printf("\n");
}

bool SqList_del(SqList &L,ElemType local,ElemType &x){
    if (local<1||local>L.len){
        return false;
    }
    x=L.data[local-1];
    for (int j = local; j < L.len; j++) {
        L.data[j-1]=L.data[j];
    }
    L.len--;
    return true;
}

int SqList_search(SqList L,ElemType ele){
    for (int i = 0; i < L.len; i++) {
        if (L.data[i]==ele){
            return i+1;
        }
    }
}

int SqList_Get(SqList &L,ElemType local){

    return L.data[local-1];
}
//顺序表的创建、插入、输出、删除
//SqList L;
//bool ret;
//int x;
//L.data[0]=1;
//L.data[1]=2;
//L.data[2]=3;
//L.len=3;
//SqList_Get(L,2);
//printf("%d\n",SqList_Get(L,2));
//ret=SqList_insert(L,2,7);
//if (ret){
//printf("Insert success:\n");
//Print_SqList(L);
//} else{
//printf("Insert fail!\n");
//}
//ret= SqList_del(L,2,x);
//if (ret){
//printf("Del success:%d\n",x);
//Print_SqList(L);
//} else{
//printf("Del faile!\n");
//}
//printf("Local:%d", SqList_search(L,3));