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

  int maxSubArray(vector<int> &nums)
  {
    // if there could be negative elements as well.. see all the possible subarrays that could be made...

    vector<vector<int>> mem(nums.size() + 1, vector<int>(nums.size() + 1, INT_MIN));

    for (int i = nums.size() - 1; i >= 0; i--)
    {
      for (int j = nums.size() - 1; j >= 0; j--)
      {
        if (i <= j)
        {
          int sum = findSum(nums, i, j);
          mem[i][j] = max(sum, max(mem[i + 1][j], mem[i][j + 1]));
        }
      }
    }

    return mem[0][0];
  }
};