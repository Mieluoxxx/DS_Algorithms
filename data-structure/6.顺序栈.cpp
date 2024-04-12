#include <iostream>
using namespace std;

#define MaxSize 10
#define ElemType int

typedef struct{
    ElemType data[MaxSize];
    int top;    // 栈顶指针
} SqStack;

void InitStack(SqStack &S){
    S.top = -1;
}

bool StackEmpty(SqStack S){
    return (S.top == -1);
}

bool Push(SqStack &S, ElemType x){
    if (S.top == MaxSize - 1)   return false;   // 栈满
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, char &x){
    if (S.top == -1)   return false;   // 栈空
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, ElemType &x){
    if (S.top == -1)   return false;   // 栈空
    x = S.data[S.top];
    return true;
}

bool DestroyStack(SqStack &S){
    S.top = -1;
    return true;
}

int main(){
    SqStack S;
    return 0;
}

bool bracketCheck(char str[], int length){
    SqStack S;
    InitStack(S);
    for(int i = 0; i < length; i++){
        if (str[i]=='(' || str[i]=='[' || str[i]=='{')
            Push(S, str[i]);
        else {
            if(StackEmpty(S))   return false;
        }

        char topElem;
        Pop(S, topElem);
        if (str[i]==')' && topElem!='(')   return false;
        if (str[i]==']' && topElem!='[')   return false;
        if (str[i]=='}' && topElem!='{')   return false;
    }
    return StackEmpty(S);
}