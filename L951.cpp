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
  bool helperFunc(TreeNode *node1, TreeNode *node2)
  {
    if (node1 == NULL && node2 == NULL)
    {
      return true;
    }
    else if (node1 != NULL && node2 != NULL)
    {
      // both are not null
      if (node1->val == node2->val)
      {
        TreeNode *leftChild1 = node1->left;
        TreeNode *rightChild1 = node1->right;
        TreeNode *leftChild2 = node2->left;
        TreeNode *rightChild2 = node2->right;
        if (leftChild1 != NULL && leftChild2 != NULL && rightChild1 != NULL && rightChild2 != NULL)
        {
          if (leftChild1->val == rightChild2->val && rightChild1->val == leftChild2->val)
          {
            // just flip the subtrees... (of second tree)
            TreeNode *temp = node2->left;
            node2->left = node2->right;
            node2->right = temp;
            return helperFunc(node1->left, node2->left) && helperFunc(node1->right, node2->right);
          }
          else if (leftChild1->val == leftChild2->val && rightChild1->val == rightChild2->val)
          {
            return helperFunc(node1->left, node2->left) && helperFunc(node1->right, node2->right);
          }
          else
          {
            return false;
          }
        }
        else if (leftChild1 == NULL && leftChild2 == NULL && rightChild1 == NULL && rightChild2 == NULL)
        {
          return true;
        }
        else if (leftChild1 != NULL && rightChild2 != NULL && leftChild2 == NULL && rightChild1 == NULL)
        {
          // swap it...
          if (leftChild1->val == rightChild2->val)
          {
            TreeNode *temp = node2->left;
            node2->left = node2->right;
            node2->right = temp;
            return helperFunc(node1->left, node2->left);
          }
          else
          {
            return false;
          }
        }
        else if (rightChild1 != NULL && leftChild2 != NULL && leftChild1 == NULL && rightChild2 == NULL)
        {
          if (rightChild1->val == leftChild2->val)
          {
            TreeNode *temp = node2->left;
            node2->left = node2->right;
            node2->right = temp;
            return helperFunc(node1->right, node2->right);
          }
          else
          {
            return false;
          }
        }
        else if (leftChild1 == NULL && leftChild2 == NULL && rightChild1 != NULL && rightChild2 != NULL)
        {
          if (rightChild1->val == rightChild2->val)
          {
            return helperFunc(rightChild1, rightChild2);
          }
          else
          {
            return false;
          }
        }
        else if (leftChild1 != NULL && leftChild2 != NULL && rightChild1 == NULL && rightChild2 == NULL)
        {
          if (leftChild1->val == leftChild2->val)
          {
            return helperFunc(leftChild1, leftChild2);
          }
          else
          {
            return false;
          }
        }
        else
        {
          return false;
        }
      }
      else
      {
        return false;
      }
    }
    else
    {
      // one of them is null mean
      return false;
    }
  }

  bool flipEquiv(TreeNode *root1, TreeNode *root2)
  {
    if (root1 == NULL && root2 == NULL)
    {
      return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
      return false;
    }
    else
    {
      return helperFunc(root1, root2);
    }
  }
};