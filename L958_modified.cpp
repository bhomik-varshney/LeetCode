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
  bool isCompleteTree(TreeNode *root)
  {
    queue<TreeNode *> q;
    q.push(root);
    bool stop = false;
    while (!q.empty())
    {
      TreeNode *currNode = q.front();
      if (!stop)
      {
        if (currNode != NULL && currNode->left != NULL && currNode->right != NULL)
        {
          q.push(currNode->left);
          q.push(currNode->right);
          q.pop();
        }
        else if(currNode != NULL && currNode->left != NULL && currNode->right == NULL)
        {
          q.push(currNode->left);
          q.pop();
          stop = true;
        }
        else if(currNode != NULL && currNode->left == NULL && currNode->right != NULL)
        {
          return false;
        }
        else
        {
          stop = true;
          q.pop();
        }
      }
      else
      {
        if(currNode != NULL && currNode->left != NULL || currNode->right != NULL)
        {
          return false;
        }
        else
        {
          q.pop();
        }
      }
    }
    return true;
  }
};