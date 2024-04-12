#include <iostream>
using namespace std;

#define ElemType int
#define MaxSize 10

typedef struct{
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue &Q){
    Q.front = Q.rear = 0;
}

bool isEmpty(SqQueue Q){
    return (Q.front == Q.rear);
}

bool EnQueue(SqQueue &Q, ElemType x){
    if(Q.rear==MaxSize-1) return false;
    Q.data[Q.rear] = x;
    Q.rear += 1;
    return true;
}

// 循环队列
bool EnQueue(SqQueue &Q, ElemType x){
    if((Q.rear+1)%MaxSize == Q.front)   return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1)%MaxSize;
}

bool DeQueue(SqQueue &Q, ElemType &x){
    if(Q.front == Q.rear) return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1)%MaxSize;
    return true;
    (Q.rear+MaxSize-Q.front)%MaxSize;
}

ElemType GetHead(SqQueue Q, ElemType &x){
    if(Q.front == Q.rear)   return false;
    x = Q.data[Q.front];
    return true;
}

int main(){
    SqQueue Q;
    InitQueue(Q);
    return 0;
}