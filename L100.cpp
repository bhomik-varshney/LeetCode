#include <iostream>

using namespace std;

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
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    // just simply check whether they are equal or not, their left must be same, their right must be same as well...
    if (p != NULL && q != NULL)
    {
      if (p->val != q->val)
      {
        return false;
      }
      else
      {
        TreeNode *leftChildp = p->left;
        TreeNode *rightChildp = p->right;
        TreeNode *leftChildq = q->left;
        TreeNode *rightChildq = q->right;
        return isSameTree(leftChildp, leftChildq) && isSameTree(rightChildp, rightChildq);
      }
    }
    else if (p == NULL && q == NULL)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};