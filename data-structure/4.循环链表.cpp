#include <iostream>
using namespace std;

#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));
    if (L==NULL)    return false;
    L->next = L;
    return true;
}

bool isEmpty(LinkList L){
    return (L->next == L);
}

bool isTail(LinkList L, LNode *p){
    return (p->next==L);
}

int main(){
    return 0;
}