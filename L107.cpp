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
  vector<vector<int>> levelOrderBottom(TreeNode *root)
  {
    vector<vector<int>> res;
    queue<pair<TreeNode *, int>> q; // it has <ptr,level>
    pair<TreeNode *, int> p = {root, 0};
    vector<int> temp;
    q.push(p);
    int currLevel = 0;

    while (!q.empty())
    {
      TreeNode *currNode = q.front().first;
      int currNodeLevel = q.front().second;
      if (currNode == NULL)
      {
        q.pop();
      }
      else
      {
        if (currNodeLevel == currLevel)
        {
          temp.push_back(currNode->val);
        }
        else
        {
          res.push_back(temp);
          temp.clear();
          temp.push_back(currNode->val);
          currLevel++;
        }
        q.pop();
        TreeNode *leftChild = currNode->left;
        TreeNode *rightChild = currNode->right;

        if (currNode->left != NULL && currNode->right != NULL)
        {
          // push left child then right child....
          pair<TreeNode *, int> p1 = {leftChild, currNodeLevel + 1};
          q.push(p1);
          pair<TreeNode *, int> p2 = {rightChild, currNodeLevel + 1};
          q.push(p2);
        }
        else if (currNode->left != NULL && currNode->right == NULL)
        {
          pair<TreeNode *, int> p1 = {leftChild, currNodeLevel + 1};
          q.push(p1);
        }
        else if (currNode->left == NULL && currNode->right != NULL)
        {
          pair<TreeNode *, int> p2 = {rightChild, currNodeLevel + 1};
          q.push(p2);
        }
      }
    }
    if (!temp.empty())
    {
      res.push_back(temp);
    }

    // now reverse the res vectors...
    int low = 0;
    int high = res.size() - 1;
    while (low <= high)
    {
      vector<int> temp = res[low];
      res[low] = res[high];
      res[high] = temp;
      low++;
      high--;
    }
    return res;
  }
};