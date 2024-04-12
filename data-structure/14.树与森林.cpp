#include <iostream>
using namespace std;

#define MAX_TREE_SIZE 100
#define ElemType int

// 双亲表示法
typedef struct {
    ElemType data;
    int parent; // 双亲位置
} PTNode;

typedef struct {
    PTNode nodes[MAX_TREE_SIZE];
    int n; // 结点数
} PTree;


// 孩子表示法
typedef struct CTNode {
    int child;
    struct CTNode *next;
};

typedef struct {
    ElemType data;
    ChildPtr *firstChild;
} CTBox;

typedef struct {
    CTBox nodes[MAX_TREE_SIZE];
    int n, r; // 结点数和根的位置
} CTree;


// 孩子兄弟表示法
typedef struct CSNode {
    ElemType data;
    struct CSNode *firstChild, *nextSibling;
} CSNode, *CSTree;
