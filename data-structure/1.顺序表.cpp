#include <iostream>
using namespace std;

#define MAXSIZE 50
#define InitSize 100
#define ElemType int

typedef struct {    // 静态顺序表
    ElemType data[MAXSIZE]; // 分配存储空间，可能存在脏数据
    int length;
}SqList;

void InitList(SqList &L) {
    for (int i = 0; i < MAXSIZE; i++) L.data[i] = 0; // 消除脏数据
    L.length = 0;
}

bool InsertList(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1)   return false;
    if (L.length >= MAXSIZE)    return false;
    for (int j = L.length; j >= i; j--) L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}


bool DeleteList(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length)    return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++) L.data[j - 1] = L.data[j];
    L.length--;
    return true;    
}

ElemType LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) return i + 1;
    }
    return 0;
}

ElemType GetElem(SqList L, int i) {
    return L.data[i - 1];
}


int main(){
    SqList L;
    
    InitList(L);
    
    InsertList(L, 1, 1);
    InsertList(L, 2, 2);
    InsertList(L, 3, 3);
    InsertList(L, 4, 4);
    
    int e = -1;
    if (DeleteList(L, 4, e)) {
        cout << "删除成功，被删除元素为:" << e << endl;
    } else {
        cout << "删除失败" << endl;
    }

    cout << "顺序表长度为:" << L.length << endl;
    cout << "顺序表第2个元素为:" << GetElem(L, 2) << endl;
    cout << "顺序表中元素3的位置为:" << LocateElem(L, 3) << endl;
    return 0;
}


typedef struct {    // 动态顺序表
    ElemType *data;
    int maxsize, length;
}SeqList;

/**
 * 不同的分配方式
 * C: L.data = (ElemType *)malloc(InitSize * sizeof(ElemType));
 * Cpp: L.data = new ElemType[InitSize];
*/
void InitList(SeqList &L) {
    // L.data = (ElemType *)malloc(InitSize * sizeof(ElemType));
    L.data = new ElemType[InitSize];
    L.length = 0;
    L.maxsize = InitSize;
}

void IncreaseSize(SeqList &L, int len) {
    ElemType *tmp = L.data; // 保存原来的数据
    // L.data = (ElemType *)realloc(L.data, (L.maxsize + len) * sizeof(ElemType));
    L.data = new ElemType[L.maxsize + len];    // 重新分配空间
    for(int i = 0; i < L.length; i++) L.data[i] = tmp[i];   // 复制数据
    delete[] tmp;   // 释放原来的空间
    // free(tmp);   
}
