#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
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
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> res;
    queue<pair<TreeNode *, int>> q;
    pair<TreeNode *, int> p = {root, 0};
    q.push(p);
    int currLevel = 0;
    vector<int> temp;
    if (root != NULL)
    {
      while (!q.empty())
      {
        TreeNode *curr = q.front().first;
        int levelOfCurr = q.front().second;
        if (levelOfCurr == currLevel)
        {
          temp.push_back(curr->val);
        }
        else
        {
          currLevel++;
          res.push_back(temp);
          temp.clear();
          temp.push_back(curr->val);
        }
        // simply add the child to the queue...
        q.pop();
        TreeNode *leftChild = curr->left;
        TreeNode *rightChild = curr->right;
        if (leftChild != NULL)
        {
          pair<TreeNode *, int> p1 = {leftChild, levelOfCurr + 1};
          q.push(p1);
        }
        if (rightChild != NULL)
        {
          pair<TreeNode *, int> p2 = {rightChild, levelOfCurr + 1};
          q.push(p2);
        }
      }
      res.push_back(temp);
      return res;
    }
    else
    {
      return res;
    }
  }
};