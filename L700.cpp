#include <iostream>
using namespace std;
//  Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  void helperFunc(TreeNode *node, int val, TreeNode *&res)
  {
    if (node == NULL)
    {
      return;
    }
    if (node->val == val)
    {
      res = node;
    }
    helperFunc(node->left, val, res);
    helperFunc(node->right, val, res);
  }
  TreeNode *searchBST(TreeNode *root, int val)
  {
    TreeNode *res = NULL;
    helperFunc(root, val, res);
    return res;
  }
};