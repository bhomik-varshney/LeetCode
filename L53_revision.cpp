#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    // if i have a particular element, i may take it, or not take it and move furthur from it, and going on making new subarray...
    int currSum = 0;
    int best_ending = nums[0];
    int res = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
      // we may take it or not take it..
      // prev ans + nums[i] or nums[i]...
      int verdict1 = currSum + nums[i];
      int verdict2 = nums[i];

      if (verdict1 > verdict2)
      {
        res = max(res, verdict1);
        currSum = verdict1;
      }
      else
      {
        res = max(res, verdict2);
        currSum = verdict2;
      }
    }
    return res;
  }
};