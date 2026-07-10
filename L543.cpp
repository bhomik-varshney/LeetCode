#include <iostream>
#include <queue>

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
  int height(TreeNode *node)
  {
    int res = 0;
    if (node == NULL)
    {
      return res;
    }
    else
    {
      res++;
      return res + max(height(node->left), height(node->right));
    }
  }
  int diameterOfBinaryTree(TreeNode *root)
  {
    // not only for the root, do it for every node...
    int res = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      TreeNode *node = q.front();
      int leftHeight = height(node->left);
      int rightHeight = height(node->right);
      if (leftHeight + rightHeight > res)
      {
        res = leftHeight + rightHeight;
      }
      q.pop();
      if (node->left != NULL)
      {
        q.push(node->left);
      }
      if (node->right != NULL)
      {
        q.push(node->right);
      }
    }
    return res;
  }
};