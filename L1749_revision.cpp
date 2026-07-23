#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxAbsoluteSum(vector<int> &nums)
  {
    // see the minimum sum as well.
    int maxSum = nums[0];
    int minSum = nums[0];
    int res = abs(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
      // see this as...
      int v1 = maxSum + nums[i];
      int v2 = minSum + nums[i];
      int v3 = nums[i];

      res = max(res, max(abs(v1), max(abs(v2), abs(v3))));

      maxSum = max(v1, max(v2, v3));
      minSum = min(v1, min(v2, v3));
    }

    return res;
  }
};