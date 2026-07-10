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
  void inorderTraversal(TreeNode *node, int &k, TreeNode *&res)
  {
    if (node == NULL)
    {
      return;
    }

    else
    {
      inorderTraversal(node->left, k, res);
      k--; // for the particular node...
      if (k == 0)
      {
        res = node;
        return;
      }
      inorderTraversal(node->right, k, res);
    }
  }
  int kthSmallest(TreeNode *root, int k)
  {
    TreeNode *res;
    inorderTraversal(root, k, res);
    return res->val;
  }
};