#include <iostream>
#include <queue>
#include <vector>
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
  int level(TreeNode *node)
  {
    int res = 0;
    if (node == NULL)
    {
      return res;
    }
    res++;
    int leftLevel = level(node->left);
    int rightLevel = level(node->right);
    return res + max(leftLevel, rightLevel);
  }

  void helperFunc(TreeNode *node, TreeNode *&res)
  {
    int leftLevel = level(node->left);
    int rightLevel = level(node->right);

    if (leftLevel > rightLevel)
    {
      // answer would be at right...
      helperFunc(node->left, res);
    }
    if (leftLevel < rightLevel)
    {
      helperFunc(node->right, res);
    }
    if (leftLevel == rightLevel)
    {
      res = node;
      return;
    }
  }

  TreeNode *lcaDeepestLeaves(TreeNode *root)
  {
    // using DFS...
    if (root->left == NULL && root->right == NULL)
    {
      return root;
    }
    TreeNode *res = NULL;
    helperFunc(root, res);
    return res;
  }
};