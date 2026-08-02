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
  int findMax(TreeNode *node)
  {
    // find the maximum value in this Tree...
    int res = INT_MIN;
    if (node == NULL)
    {
      return res;
    }

    // now change the value by it....
    if (res < node->val)
    {
      res = node->val;
    }

    int fromLeftSubtree = findMax(node->left);
    int fromRightSubtree = findMax(node->right);
    res = max(res, max(fromLeftSubtree, fromRightSubtree));
    return res;
  }

  void helperFunc(TreeNode *node, int &res)
  {
    // check if the node is not null...
    if (node == NULL)
    {
      return;
    }

    // now find the maximum of its left and right...
    // now find the maximum from its left subtree, and right Subtre...
    int leftMax = findMax(node->left);
    int rightMax = findMax(node->right);

    if (node->val >= leftMax && node->val >= rightMax)
    {
      res++;
    }

    helperFunc(node->left, res);
    helperFunc(node->right, res);
    return;
  }

  int countDominantNodes(TreeNode *root)
  {
    // dominant nodes in a binary Tree..
    // dominant node would be the one
    // take the particular node, check what is the maximum node value, in its tree rooted at it...
    // if the maximum value is equal to the one then , take it in answer...
    int res = 0;
    helperFunc(root, res);
    return res;
  }
};