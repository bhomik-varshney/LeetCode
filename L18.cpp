#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  // but in this case, duplicacy would be there..., to remove duplicacy just sort it and using 2 pointer remove duplicacy....

  void helperFunc(vector<int> &nums, int target, int numCount, int currSum, int idx, vector<int> &temp, vector<vector<int>> &res)
  {
    if (numCount == 4)
    {
      if (currSum == target)
      {
        res.push_back(temp);
      }
    }

    if (idx == nums.size())
    {
      return;
    }

    // make otherwise situation, if we take the current idx value or not...
    // take that num...
    temp.push_back(nums[idx]);
    helperFunc(nums, target, numCount + 1, currSum + nums[idx], idx + 1, temp, res);
    temp.pop_back();
    helperFunc(nums, target, numCount, currSum, idx + 1, temp, res);
  }

  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    vector<int> temp;
    vector<vector<int>> res;
    helperFunc(nums, target, 0, 0, 0, temp, res);
    return res;
  }
};