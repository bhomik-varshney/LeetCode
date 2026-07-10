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
  void find(TreeNode *node1, TreeNode *node2, vector<TreeNode *> &v) // node 1 is for subtree and node2 is for the main tree
  {
    if (node1 == NULL)
    {
      return;
    }
    else
    {
      if (node2 != NULL)
      {
        if (node2->val == node1->val)
        {
          v.push_back(node2);
        }
        find(node1, node2->left, v);
        find(node1, node2->right, v);
      }
      else
      {
        return;
      }
    }
  }

  bool same(TreeNode *node1, TreeNode *node2)
  {
    if (node1 != NULL && node2 != NULL)
    {
      if (node1->val == node2->val)
      {
        return same(node1->left, node2->left) && same(node1->right, node2->right);
      }
      else
      {
        return false;
      }
    }

    else if (node1 == NULL && node2 == NULL)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool isSubtree(TreeNode *root, TreeNode *subRoot)
  {
    // find how many of them have root->val == node->val in subtree
    vector<TreeNode *> v;
    find(subRoot, root, v);

    for (auto i : v)
    {
      // now call for the function same
      if (same(subRoot, i) == true)
      {
        return true;
      }
    }
    return false;
  }
};