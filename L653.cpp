#include <iostream>
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
  void inorderTraversal(TreeNode *node, vector<int> &res)
  {
    if (node == NULL)
    {
      return;
    }
    inorderTraversal(node->left, res);
    res.push_back(node->val);
    inorderTraversal(node->right, res);
  }

  bool findTarget(TreeNode *root, int k)
  {
    vector<int> res;
    inorderTraversal(root, res);
    int low = 0;
    int high = res.size() - 1;
    // use two pointer approach in sorted array...
    while (low < high)
    {
      int sum = res[low] + res[high];
      if (sum == k)
      {
        return true;
      }
      else if (sum < k)
      {
        low++;
      }
      else
      {
        high--;
      }
    }
    return false;
  }
};