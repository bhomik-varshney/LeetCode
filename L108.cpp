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
  TreeNode *helperFunc(vector<int> &nums, int low, int high)
  {
    if (low <= high)
    {
      int mid = low + (high - low) / 2;
      int nodeVal = nums[mid];
      TreeNode *newNode = new TreeNode(nodeVal);

      newNode->left = helperFunc(nums, low, mid - 1);
      newNode->right = helperFunc(nums, mid + 1, high);

      return newNode;
    }
    else
    {
      return NULL;
    }
  }

  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    int low = 0;
    int high = nums.size() - 1;
    return helperFunc(nums, low, high);
  }
};