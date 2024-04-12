#include <iostream>
using namespace std;

struct TreeNode {
  int val; // 节点值
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};


int main() {
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

  /* 插入与删除节点 */
  TreeNode* P = new TreeNode(0);
  // 在 n1 -> n2 中间插入节点 P
  n1->left = P;
  P->left = n2;
  // 删除节点 P
  n1->left = n2;
  return 0;
}
