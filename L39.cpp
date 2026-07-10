#include <iostream>

using namespace std;

class Solution
{
public:
  void helperFunc(vector<int> &candidates, int currSum, int &start, int &target, vector<int> &temp, vector<vector<int>> &res)
  {
    if (currSum == target)
    {
      res.push_back(temp);
      return;
    }
    if (currSum > target)
    {
      return;
    }
    if (currSum < target)
    {
      for (int i = start; i < candidates.size(); i++)
      {
        // take that element and add into the res...
        temp.push_back(candidates[i]);
        currSum += candidates[i];
        helperFunc(candidates, currSum, i, target, temp, res);
        currSum -= candidates[i];
        temp.pop_back();
      }
    }
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    int currSum = 0;
    vector<int> temp;
    int start = 0;
    vector<vector<int>> res;
    helperFunc(candidates, currSum, start, target, temp, res);
    return res;
  }
};

int main()
{
  Solution s1;
  vector<int> candidates = {2, 3, 6, 7};
  vector<vector<int>> res = s1.combinationSum(candidates, 7);
  cout << res.size() << endl;
}