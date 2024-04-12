#include <iostream>
using namespace std;

#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

// 不带头结点的单链表
bool InitList(LinkList &L){
    L = NULL; // 空表
    return true;
}

// 判断单链表是否为空
bool isEmpty(LinkList L){
    return (L == NULL);
}

// 不带头结点的按位插入
bool InsertList(LinkList &L, ElemType e, int i){
    if (i < 1) return false;
    if (i == 1) {
        LNode *s = (LNode*)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }
    LNode *p;   // 用于扫描的结点
    int j = 1;
    p = L;
    while(p!=NULL && j < i-1){
        p=p->next;
        j++;
    }
    if(p==NULL) return false;
    // LNode *s = (LNode*)malloc(sizeof(LNode));
    LNode *s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}


// 带头结点的单链表
bool InitListH(LinkList &L){
    // L = (LNode *)malloc(sizeof(LNode));
    L = new LNode;  // 头结点不存储数据，只是为了简化代码
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

// 判断单链表是否为空
bool isEmptyH(LinkList L){
    return (L->next == NULL);
}

// 带头结点的按位插入
bool InsertListH(LinkList &L, ElemType e, int i){
    if (i < 1)  return false;
    LNode *p;   // 用于扫描的结点
    int j = 0;
    p = L;      // L指向头结点，头结点为第0个结点，不带数据
    while(p!=NULL && j < i-1){  // 循环找到第i个结点的前面一个结点
        p = p->next;
        j++;
    }
    if (p==NULL)    return false;   // i值不合理
    
    // LNode *s = (LNode*)malloc(sizeof(LNode));
    LNode *s = new LNode;   // 等待插入的结点
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 带头结点的后插操作
bool InsertNextNodeH(LNode *p, ElemType e){
    if (p == NULL)  return false;
    // LNode *s = (LNode*)malloc(sizeof(LNode));
    LNode *s = new LNode;
    if (s == NULL)  return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// // 带头结点的前插操作 O(n)
// bool InsertPriorityNodeH(LinkList L, LNode *p, ElemType e){
//     // 寻找前驱结点
// }

// 带头结点的前插操作 O(1)
bool InsertPriorityNodeH(LNode *p, ElemType e){
    // 逻辑前插
    if (p==NULL)    return false;
    LNode *s = new LNode;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    return true;
}

// 带头结点的前插操作 O(1)
bool InsertPriorityNodeH(LNode *p, LNode *s){
    // 逻辑前插
    if (p==NULL || s == NULL)    return false;
    s->next = p->next;
    p->next = s;
    ElemType tmp = p->data;
    p->data = s->data;
    s->data = tmp;
    return true;
}

// 带头结点的删除 O(n)
bool ListDeleteH(LinkList &L, int i, ElemType &e){
    if (i < 1)  return false;
    LNode *p;   // 用于扫描的结点
    int j = 0;
    p = L;
    while(p!=NULL && j < i-1){  // 循环找到第i个结点的前面一个结点
        p = p->next;
        j++;
    }
    if (p==NULL)    return false;   // i值不合理
    if(p->next == NULL) return false;    // 第i个结点不存在
    LNode *q = p->next; // q指向待删除的结点
    e = q->data;
    p->next = q->next;
    // free(q);
    delete q;
    return true;
}

// 带头结点的删除 O(1)
bool ListDeleteH(LNode *p){ 
    if (p==NULL)    return false;
    LNode *q = p->next;
    p->data = q->next->data;    // 不能删除最后一个元素
    p->next = q->next;
    // free(q);
    delete q;
    return true;
}




// 返回查找第i个结果 O(n)
LNode* GetElem(LinkList L, int i){
    int j = 1;
    LNode *p = L->next;
    if (i < 0) return L;
    if (i < 1)  return NULL;
    while (p != NULL && j < i){
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找
LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    while(p!=NULL && p->data!=e){
        p = p->next;
    }  
    return p;
}

// 求表的长度
int Length(LinkList L){
    int len = 0;
    LNode *p = L;
    while(p->next != L){
        p = p->next;
        len++;
    } 
    return len;
}

// 尾插法 - 正向建立单链表
LinkList List_TailInsert(LinkList &L) { 
    int x;
    // L = (LinkList) malloc(sizeof(LNode));
    L = new LNode;
    LNode *s, *r = L;   // r是表尾指针
    scanf("%d", &x);
    while(x!=9999){
        // s = (LNode*)malloc(sizeof(LNode));
        s = new LNode;
        s->data = x;
        r->next = s;
        r = s;

        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

// 头插法 - 链表逆置
LinkList List_HeadInsert(LinkList &L){
    LNode *s;
    int x;
    // L = (LinkList)malloc(sizeof(LNode));
    L = new LNode;
    scanf("%d", &x);
    while(x != 9999){
        // s = (LNode*)malloc(sizeof(LNode));
        s = new LNode;
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

void PrintList(LinkList L){
    LNode *p = L->next;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void DestroyList(LinkList &L){
    LNode *p = L, *q = L->next;
    while(q != NULL){
        // free(p);
        delete p;
        p = q;
        q = p->next;
    }
    // free(p);
    delete p;
    L = NULL;
}

int main() {
    LinkList L;
    
    // Test InitList and isEmpty
    InitList(L);
    cout << "Is L empty? " << (isEmpty(L) ? "Yes" : "No") << endl;

    L = List_TailInsert(L);
    cout << "Is L empty? " << (isEmpty(L) ? "Yes" : "No") << endl;
    PrintList(L);

    DestroyList(L);
    cout << "Is L empty? " << (isEmpty(L) ? "Yes" : "No") << endl;

    L = List_HeadInsert(L);
    cout << "Is L empty? " << (isEmpty(L) ? "Yes" : "No") << endl;
    PrintList(L);
    

    return 0;
}
