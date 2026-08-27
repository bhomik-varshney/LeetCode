#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> findDisappearedNumbers(vector<int> &nums, int lower, int upper)
  {
    vector<vector<int>> res;
    int curr = lower - 1;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
      // we have to see there must be bigger than diff of 1...
      int diff = nums[i] - curr;
      if (diff > 1)
      {
        if (nums[i] <= upper)
        {
          // only we can take it...
          vector<int> temp = {curr + 1, nums[i] - 1};
          res.push_back(temp);
          curr = nums[i];
        }
        else
        {
          break;
        }
      }
      else if (diff >= 0 && diff <= 1)
      {
        curr = nums[i];
      }
      else
      {
        continue;
      }
    }

    if (upper > curr)
    {
      vector<int> temp = {curr + 1, upper};
      res.push_back(temp);
    }

    return res;
  }
};