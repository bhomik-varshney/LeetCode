#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int findSum(vector<int> &nums, int low, int high)
  {
    int sum = 0;
    for (int i = low; i <= high; i++)
    {
      sum += nums[i];
    }
    return sum;
  }

  void helperFunc(vector<int> &nums, int low, int high, int &res)
  {
    if (low > high)
    {
      return;
    }

    if (low <= high && high == nums.size())
    {
      // simply return from it..
      return;
    }

    // we can increase the low value, increase the high value...
    // or we can simply remain there...
    // check the current one...
    int sum = findSum(nums, low, high);
    if (sum > res)
    {
      res = sum;
    }
    // find answers for low++ and high++;

    helperFunc(nums, low + 1, high, res);
    helperFunc(nums, low, high + 1, res);
  }

  int maxSubArray(vector<int> &nums)
  {
    // if there could be negative elements as well.. see all the possible subarrays that could be made...
    int res = INT_MIN;
    helperFunc(nums, 0, 0, res);
    return res;
  }
};