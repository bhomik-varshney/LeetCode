#include <iostream>
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
  void helperFunc(TreeNode *node, vector<int> &res)
  {
    if (node == NULL)
    {
      return;
    }
    helperFunc(node->left, res);
    helperFunc(node->right, res);
    res.push_back(node->val);
  }

  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> res;
    helperFunc(root, res);
    return res;
  }
};