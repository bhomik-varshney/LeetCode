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
  bool helperFunc(TreeNode *n1, TreeNode *n2)
  {
    // now check in both of them....
    if (n1 == NULL && n2 == NULL)
    {
      return true;
    }
    else if (n1 != NULL && n2 == NULL)
    {
      return false;
    }
    else if (n1 == NULL && n2 != NULL)
    {
      return false;
    }
    else
    {
      // check if that node's child are invertedly same or not...
      // these node's data must be same..
      if (n1->val == n2->val)
      {
        return helperFunc(n1->left, n2->right) && helperFunc(n1->right, n2->left);
      }
      else
      {
        return false;
      }
    }
  }

  bool isSymmetric(TreeNode *root)
  {
    // root is always there..
    if (root->left != NULL && root->right != NULL && root->left->val == root->right->val)
    {
      // now check for it...
      return helperFunc(root->left, root->right);
    }
    else if (root->left == NULL && root->right == NULL)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};