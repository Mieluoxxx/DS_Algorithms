#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
  int val; // 节点值
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

void preOrder(TreeNode *root) {
    if (root == NULL)  return ;
    stack<TreeNode *> nodestack;
    nodestack.push(root);   // 根节点入栈

    while(!nodestack.empty()){  // 栈不为空
        TreeNode *node = nodestack.top();   // 保存栈顶节点
        printf("%d ", node->val);
        nodestack.pop();    // 出栈
        
        if(node->right) nodestack.push(node->right);
        if(node->left) nodestack.push(node->left);
    }
}

void InOrder(TreeNode *root) {
    if (root == NULL)   return ;
    stack<TreeNode *> nodestack;
    TreeNode *current = root;   // 维护一个current指针

    while(current || !nodestack.empty()) {
        // 当前节点非空，沿着左子树入栈
        while(current) {
            nodestack.push(current);
            current = current->left;
        }
        // 此时栈顶节点没有左子树，或已经访问完左子树
        current = nodestack.top();  // 去栈顶节点
        printf("%d ", current->val);
        nodestack.pop();    // 出栈
        current = current->right;   // 右子树入栈
    }
}

void postOrder(TreeNode *root) {
    if (root == NULL)   return ;
    TreeNode *current = root;   // 维护一个current指针
    TreeNode *visit = root;    // 维护一个visit指针，利用二叉树无环图的性质

    stack<TreeNode *> nodestack;
    // 当前节点非空，或栈不为空
    while(current || !nodestack.empty()) {
        while(current) {
            nodestack.push(current);    // 当前节点入栈
            current = current->left;    // 沿着左子树入栈
        }
        // 此时栈顶节点没有左子树，或已经访问完左子树
        current = nodestack.top();  // 取栈顶节点
        // 如果栈顶节点有右子树，且未被访问过
        if(current->right && current->right != visit) {
            current = current->right;   // 右子树入栈
        } else {
            printf("%d ", current->val);
            visit = current;    // 标记当前节点已被访问
            current = NULL;     // 当前节点置空
            nodestack.pop();    // 出栈
        }
    }
}

int main(){
    // 初始化节点
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);

    // 构建节点之间的引用（指针）
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;

    preOrder(n1);
    printf("\n");
    InOrder(n1);
    printf("\n");
    postOrder(n1);
    return 0;
}