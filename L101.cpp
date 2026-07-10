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
  bool helperFunc(TreeNode *node1, TreeNode *node2)
  {
    if (node1 != NULL || node2 != NULL)
    {
      if (node1 != NULL && node2 != NULL && node1->val == node2->val)
      {
        TreeNode *leftChild1 = node1->left;
        TreeNode *rightChild1 = node1->right;
        TreeNode *leftChild2 = node2->left;
        TreeNode *rightChild2 = node2->right;

        return helperFunc(leftChild1, rightChild2) && helperFunc(rightChild1, leftChild2);
      }
      else
      {
        return false;
      }
    }
    else
    {
      return true;
    }
  }
  bool isSymmetric(TreeNode *root)
  {
    TreeNode *leftChild = root->left;
    TreeNode *rightChild = root->right;

    return helperFunc(leftChild, rightChild);
  }
};