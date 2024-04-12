#include <iostream>
using namespace std;

#define ElemType int

typedef struct DNode{
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

bool InitDList(DLinkList &L){
    // L = (DNode *)malloc(sizeof(DNode));
    L = new DNode;
    if (L == NULL)  return false;
    L->prior = NULL;    // 头节点的prior指针指向NULL
    L->next = NULL;
    return true;
}

bool InsertNextNode(DNode *p, DNode *s){
    if (p == NULL || s == NULL) return false;
    s->next = p->next;
    if (p->next != NULL)    // p不是最后一个节点
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

bool DeleteNextNode(DNode *p){
    if (p == NULL)  return false;
    DNode *q = p->next; // 找到p的后继节点
    if (q == NULL)  return false;
    p->next = q->next;
    if (q->next != NULL)    // q不是最后一个节点
        q->next->prior = p;
    // free(q);
    delete q;
    return true;
}

void DestroyList(DLinkList &L){
    while (L->next != NULL)
        DeleteNextNode(L);
    // free(L);
    delete L;
    L = NULL;
}

// 判断带头节点的双链表是否为空
bool isEmpty(DLinkList L){
    return (L->next == NULL);
}

int main(){
    DLinkList L;
    InitDList(L);
    cout << isEmpty(L) << endl;
    return 0;
}