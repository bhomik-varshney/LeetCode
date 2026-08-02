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

  int helperFunc(vector<int> &nums, int low, int high,vector<vector<int>> &mem)
  {
    if (low > high)
    {
      return INT_MIN;
    }

    if (low <= high && high == nums.size())
    {
      // simply return from it..
      return INT_MIN;
    }

    if(mem[low][high] != INT_MIN)
    {
        return mem[low][high];
    }

    int sum = findSum(nums,low,high);
    int a1 = helperFunc(nums,low+1,high,mem);
    int a2 = helperFunc(nums,low,high+1,mem);
    // and the one with the similar one...
    int res = max(sum,max(a1,a2));
    mem[low][high] = res;
    return res;
  }

  int maxSubArray(vector<int> &nums)
  {
    // if there could be negative elements as well.. see all the possible subarrays that could be made...
    vector<vector<int>> mem(nums.size(),vector<int>(nums.size(),INT_MIN));
    return helperFunc(nums, 0, 0, mem);
  }
};