#include <iostream>
using namespace std;

#define ElemType int

typedef struct LinkNode{
    int data;
    struct LinkNode *next;
} LinkNode;

typedef struct {
    LinkNode *front, *rear;
}LinkQueue;

// 带头节点
void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    // Q.front = Q.rear = new LinkNode;
    Q.front->next = NULL;
}

bool isEmpty(LinkQueue Q){
    return (Q.front == Q.rear);
}

void EnQueue(LinkQueue &Q, ElemType x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    // LinkNode *s = new LinkNode;
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, ElemType &x){
    if(Q.front == Q.rear)   return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(Q.rear == p) Q.rear = Q.front;
    free(p);
    return true;
}

// 不带头节点
void InitQueue(LinkQueue &Q){
    Q.front = NULL;
    Q.rear = NULL;
}

bool isEmpty(LinkQueue Q){
    return (Q.front == NULL);
}

void EnQueue(LinkQueue &Q, ElemType x){
    LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    if(Q.front == NULL){
        Q.front = s;
        Q.rear = s;
    }else{
        Q.rear->next = s;
        Q.rear = s;
    }
}

bool DeQueue(LinkQueue &Q, ElemType x){
    if (Q.front == NULL)    return false;
    LinkNode *p = Q.front;
    x = p->data;
    Q.front = p->next;
    if (Q.rear == p){
        Q.rear = NULL;
        Q.front = NULL;
    }
    free(p);
    return true;
}

int main(){
    LinkQueue Q;
    InitQueue(Q);
    return 0;
}