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
  int findIdx(vector<int> inorder, int val, int low, int high)
  {
    while (low <= high)
    {
      if (inorder[low] == val)
      {
        return low;
      }
      low++;
    }

    return -1;
  }

  TreeNode *helperFunc(vector<int> inorder, vector<int> postorder, int &idx, int low, int high)
  {
    if (idx >= 0)
    {
      int rootVal = postorder[idx];
      int rootIdx = findIdx(inorder, rootVal, low, high);
      TreeNode *newNode = new TreeNode(rootVal);
      int r1 = rootIdx - 1;
      int r2 = rootIdx + 1;
      // firstly make the right subtree and then left subtree...
      idx--;
      if (r2 > high)
      {
        newNode->right = NULL;
      }
      else
      {
        newNode->right = helperFunc(inorder, postorder, idx, r2, high);
      }
      if (r1 < low)
      {
        newNode->left = NULL;
      }
      else
      {
        newNode->left = helperFunc(inorder, postorder, idx, low, r1);
      }

      return newNode;
    }
    else
    {
      return NULL;
    }
  }

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    TreeNode *root = NULL;
    if (inorder.size() != 0)
    {
      int idx = postorder.size() - 1;
      int low = 0;
      int high = inorder.size() - 1;
      root = helperFunc(inorder, postorder, idx, low, high);
    }

    return root;
  }
};