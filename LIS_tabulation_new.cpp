#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    vector<int> LIS(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++)
    {
      int currNum = nums[i];
      // now see the numbers which are less than that. having maximum value in LIS...
      int maximumLIS = 0;
      for (int j = 0; j < i; j++)
      {
        if (nums[j] < currNum && LIS[j] > maximumLIS)
        {
          maximumLIS = LIS[j];
        }
      }

      LIS[i] = maximumLIS + 1;
    }

    // now return the maximum from the vector LIS...
    int max = 0;
    for (int i = 0; i < LIS.size(); i++)
    {
      if (LIS[i] > max)
      {
        max = LIS[i];
      }
    }
    return max;
  }
};