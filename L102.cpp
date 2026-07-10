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
  void helperFunc(queue<TreeNode *> &thisLevel, queue<TreeNode *> &nextLevel, vector<int> &temp, vector<vector<int>> &res)
  {
    // now we have to print the particular level into the temp...
    if (thisLevel.empty() && !nextLevel.empty())
    {
      res.push_back(temp);
      thisLevel = nextLevel;
      // make next Level to be empty...
      while (!nextLevel.empty())
      {
        nextLevel.pop();
      }
      while (!temp.empty())
      {
        temp.pop_back();
      }
      helperFunc(thisLevel, nextLevel, temp, res);
    }
    else if (thisLevel.empty() && nextLevel.empty())
    {
      return;
    }
    else
    {
      TreeNode *leftChild;
      TreeNode *rightChild;
      if (thisLevel.front() != NULL)
      {
        temp.push_back(thisLevel.front()->val);
        leftChild = thisLevel.front()->left;
        rightChild = thisLevel.front()->right;
        nextLevel.push(leftChild);
        nextLevel.push(rightChild);
      }
      thisLevel.pop();
      helperFunc(thisLevel, nextLevel, temp, res);
    }
  }
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<int> temp;
    vector<vector<int>> res;
    queue<TreeNode *> thisLevel;
    queue<TreeNode *> nextLevel;
    thisLevel.push(root);
    helperFunc(thisLevel, nextLevel, temp, res);
    return res;
  }
};
