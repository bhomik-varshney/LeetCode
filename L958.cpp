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
    int total = res + max(leftLevel, rightLevel);
    return total;
  }

  bool isCompleteTree(TreeNode *root)
  {
    int numLevels = level(root); // O(N)
    // now if i have n levels , then till n-1 , it would have all the complete levels or 2^l nodes where l is the level....
    // given the tree would have minimum level = 1, then just check whether it has left and right child or not...
    if (numLevels == 1)
    {
      return true;
    }
    else if (numLevels == 2)
    {
      if (root->left != NULL)
      {
        // does not matter if it has right child or not...
        return true;
      }
      else
      {
        // means it only has right Child...
        return false;
      }
    }

    else
    {
      int maxNodes = 1; // for level = 1, maximum nodes = 1
      queue<TreeNode *> q;
      q.push(root);
      // for level n, n-1 levels are complete
      numLevels--;      // for n-1 level check
      while (numLevels) // O(logN)
      {
        int size = q.size();
        numLevels--;
        if (size != maxNodes)
        {
          return false;
        }
        if (numLevels != 0)
        {
          while (size != 0)
          {
            TreeNode *node = q.front();
            if (node != NULL && node->left != NULL)
            {
              q.push(node->left);
            }
            if (node != NULL && node->right != NULL)
            {
              q.push(node->right);
            }
            q.pop();
            size--;
          }
        }
        maxNodes = maxNodes * 2;
      }

      // now we are at the last level, it must be checked as :-
      bool stop = false;
      while (!q.empty())
      {
        TreeNode *currNode = q.front();
        if (!stop)
        {
          if (currNode != NULL && currNode->left != NULL && currNode->right != NULL)
          {
            // pass the test...
            q.pop();
          }
          else if (currNode != NULL && currNode->left != NULL && currNode->right == NULL)
          {
            stop = true;
            q.pop();
          }
          else if (currNode != NULL && currNode->left == NULL && currNode->right != NULL)
          {
            return false;
          }
          else
          {
            // if both are NULL
            stop = true;
            q.pop();
          }
        }
        else
        {
          if (currNode != NULL && currNode->left != NULL || currNode->right != NULL)
          {
            return false;
          }
          q.pop();
        }
      }
      return true;
    }
  }
};