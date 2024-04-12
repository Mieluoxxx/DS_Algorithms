#include <iostream>
using namespace std;

#define ElemType int

typedef struct LinkLNode{   // 链栈的结点类型
    ElemType data;
    struct LinkLNode *top;
}LNode, *LiStack;



void InitStack(LiStack &S){
    S = NULL;
}

bool isEmpty(LiStack S){
    return (S == NULL);
}

bool Push(LiStack &S, ElemType x){
    LNode *s = new LNode;
    s->data = x;    // 新结点数据域赋值
    s->top = S;    // 新结点指针域指向栈顶
    S = s;
    return true;
}

bool Pop(LiStack &S, ElemType &x){
    if (S == NULL)  return false;
    x = S->data;
    LNode *p = S;
    S = S->top;
    delete p;
    return true;
}

bool GetTopElem(LiStack S, ElemType &x){
    if (S == NULL)  return false;
    x = S->data;
    return true;
}

void CreateStack(LiStack &S, int x) {
  int number;
  cout << "请输入要建立的栈中的元素个数：\n";
  cin >> number;
  for(int i=0; i<number; i++) {
    cout << "输入第" << i+1 << "个入栈的元素：" << endl;
    scanf("%d",&x);
    Push(S,x);
  }
}

int main(){
    LiStack S;

    return 0;
}