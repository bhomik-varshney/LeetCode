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
  void helperFunc(TreeNode *node, int &targetSum, vector<int> &temp, vector<vector<int>> &res)
  {
    int sum = 0;
    if (node == NULL)
    {
      return;
    }
    else
    {
      sum += node->val;
      temp.push_back(node->val);
      if (node->left == NULL && node->right == NULL)
      {
        // we are at the leaf node...
        if (sum == targetSum)
        {
          res.push_back(temp);
        }
      }

      targetSum -= sum;
      helperFunc(node->left, targetSum, temp, res);
      helperFunc(node->right, targetSum, temp, res);
      temp.pop_back();
      targetSum += sum;
    }
  }

  vector<vector<int>> pathSum(TreeNode *root, int targetSum)
  {
    vector<vector<int>> res;
    vector<int> temp;
    helperFunc(root, targetSum, temp, res);
    return res;
  }
};