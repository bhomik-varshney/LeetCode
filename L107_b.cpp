#include <iostream>
#include <queue>
#include <vector>

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
  void levelHelper(TreeNode *node, int &level)
  {
    if (node == NULL)
    {
      return;
    }

    level++;
    int leftLevel = 0;
    int rightLevel = 0;
    levelHelper(node->left, leftLevel);
    levelHelper(node->right, rightLevel);
    level += max(leftLevel, rightLevel);
  }

  int levels(TreeNode *node)
  {
    int res = 0;
    levelHelper(node, res);
    return res;
  }

  vector<vector<int>> levelOrderBottom(TreeNode *root)
  {
    queue<TreeNode *> q;
    vector<vector<int>> res(levels(root));
    int sizeOfRes = levels(root);
    if (root == NULL)
    {
      return res;
    }
    else
    {
      q.push(root);
      while (!q.empty())
      {
        int levelSize = q.size();
        vector<int> temp;
        while (levelSize > 0)
        {
          TreeNode *currNode = q.front();
          q.pop();
          levelSize--;
          temp.push_back(currNode->val);

          TreeNode *leftChild = currNode->left;
          TreeNode *rightChild = currNode->right;
          if (leftChild != NULL)
          {
            q.push(leftChild);
          }
          if (rightChild != NULL)
          {
            q.push(rightChild);
          }
        }
        res[sizeOfRes - 1] = temp;
        sizeOfRes--;
      }

      return res;
    }
  }
};