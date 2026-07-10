#include <iostream>
using namespace std;

// Definition for a binary tree node.
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
      int leftDepth = depth(node->left);
      int rightDepth = depth(node->right);
      return (res + max(leftDepth, rightDepth));
    }
  }
  void advancedReached(TreeNode *node, TreeNode *p, TreeNode *q, bool &findP, bool &findQ)
  {
    if (node == NULL)
    {
      return;
    }
    if (node == p)
    {
      findP = true;
    }
    if (node == q)
    {
      findQ = true;
    }

    advancedReached(node->left, p, q, findP, findQ);
    advancedReached(node->right, p, q, findP, findQ);
  }

  bool reached(TreeNode *node, TreeNode *p)
  {
    if (node == NULL)
    {
      return false;
    }
    if (node == p)
    {
      return true;
    }
    if (node != p)
    {
      return reached(node->left, p) || reached(node->right, p);
    }
  }

  void helperFunc(TreeNode *node, TreeNode *p, TreeNode *q, int &ancestorLevel, TreeNode *&res)
  {
    if (node == NULL)
    {
      return;
    }
    bool findP = false;
    bool findQ = false;
    advancedReached(node, p, q, findP, findQ); // O(N)
    if (findP && findQ && ancestorLevel > depth(node)) // if depth calulation is not removed :- O(N)
    {
      res = node;
      ancestorLevel = depth(node);
    }

    helperFunc(node->left, p, q, ancestorLevel, res);
    helperFunc(node->right, p, q, ancestorLevel, res);
  }

  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    // we have to search for every node if a particular node is there using which p and q both can be reached....
    // if yes, then among them find the one with least highest level....(in our case depth must be less)
    // new realization:- no need to find the depth, if the particular node is there , node->left and node->right would always have lower depth than node itself.. so just need to overwrite when result is being found...
    // complexity would be :- O(N)
    int ancestorLevel = INT_MAX;
    TreeNode *res = NULL;
    helperFunc(root, p, q, ancestorLevel, res);
    return res;
  }
};