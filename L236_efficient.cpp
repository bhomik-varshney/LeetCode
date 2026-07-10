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
  TreeNode *res;

  int helperFunc(TreeNode *node, TreeNode *p, TreeNode *q)
  {
    if (node == NULL)
    {
      return 0;
    }
    int left = helperFunc(node->left, p, q);
    int right = helperFunc(node->right, p, q);
    int self = 0;
    if (node == p || node == q)
    {
      self = 1;
    }
    int total = self + left + right;
    if (total == 2 && res == NULL)
    {
      res = node;
    }
    return total;
  }

  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    // we have to see if that particular node is ancestor of any 1, all (2) or none....
    helperFunc(root, p, q);
    return res;
  }
};