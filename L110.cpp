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
  int depth(TreeNode *node)
  {
    int res = 0;
    if (node == NULL)
    {
      return res;
    }
    else
    {
      res++;
      return res + max(depth(node->left), depth(node->right));
    }
  }

  bool helperFunc(TreeNode *node)
  {
    if (node == NULL)
    {
      return true;
    }
    int depthOfLeft = depth(node->left);
    int depthOfRight = depth(node->right);
    int balancedHeight = abs(depthOfLeft - depthOfRight);
    if (balancedHeight > 1)
    {
      return false;
    }
    else
    {
      return helperFunc(node->left) && helperFunc(node->right);
    }
  }
  bool isBalanced(TreeNode *root)
  {
    return helperFunc(root);
  }
};