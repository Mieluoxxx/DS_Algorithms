#include <iostream>
using namespace std;

#define MaxSize 10
#define ElemType int

typedef struct{
    ElemType data[MaxSize];
    int top0;
    int top1;
} ShStack;

void InitStack(ShStack &S){
    S.top0 = -1;
    S.top1 = MaxSize;
}

int main(){

    return 0;
}



