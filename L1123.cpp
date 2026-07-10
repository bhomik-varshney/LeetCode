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
  vector<TreeNode *> v;
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
  int LCA(TreeNode *node, int maxReached, TreeNode *&res)
  {
    if (node == NULL)
    {
      return 0;
    }
    int reached = 0;
    for (int i = 0; i < v.size(); i++)
    {
      if (v[i] == node)
      {
        reached++;
      }
    }
    int left = LCA(node->left, maxReached, res);
    int right = LCA(node->right, maxReached, res);

    if (reached + left + right == maxReached && res == NULL)
    {
      res = node;
    }

    return reached + left + right;
  }

  TreeNode *lcaDeepestLeaves(TreeNode *root)
  {
    int numLevels = level(root);

    queue<TreeNode *> q;
    q.push(root);
    while (numLevels - 1 != 0)
    {
      int size = q.size();
      while (size != 0)
      {
        TreeNode *currNode = q.front();
        if (currNode->left != NULL)
        {
          q.push(currNode->left);
        }
        if (currNode->right != NULL)
        {
          q.push(currNode->right);
        }
        q.pop();
        size--;
      }

      numLevels--;
    }

    // now the queue has leaf nodes...
    if (q.size() == 1)
    {
      return q.front();
    }
    else
    {
      int maxReached = q.size();
      while (!q.empty())
      {
        v.push_back(q.front());
        q.pop();
      }
      // means the size is 2 or above, apply LCA on those two nodes...
      TreeNode *res = NULL;
      LCA(root, maxReached, res);
      return res;
    }
  }
};