#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int helperFunc(vector<int> &nums, int index, int lastNumberIndex, vector<vector<int>> &mem1, vector<vector<int>> &mem2)
  {
    if (index == nums.size())
    {
      return 0;
    }
    // if index != nums.size()-1;
    // if the index is not the last one. just calculate if we take that, or not we have taken it...
    if (lastNumberIndex == -100000)
    {
      if (mem2[index][0] != -1)
      {
        return mem2[index][lastNumberIndex];
      }
      else
      {
        int a1 = 1 + helperFunc(nums, index + 1, index, mem1, mem2);
        int a2 = helperFunc(nums, index + 1, lastNumberIndex, mem1, mem2);
        int res = max(a1, a2);
        mem2[index][0] = res;
        return mem2[index][0];
      }
    }
    else
    {
      if (mem1[index][lastNumberIndex] != -1)
      {
        return mem1[index][lastNumberIndex];
      }
      else
      {
        if (nums[index] > nums[lastNumberIndex])
        {
          // full choice...
          int a1 = 1 + helperFunc(nums, index + 1, index, mem1, mem2);
          int a2 = helperFunc(nums, index + 1, lastNumberIndex, mem1, mem2);
          int res = max(a1, a2);
          return mem1[index][lastNumberIndex] = res;
        }
        else
        {
          // no choice..
          return mem1[index][lastNumberIndex] = helperFunc(nums, index + 1, lastNumberIndex, mem1, mem2);
        }
      }
    }
  }

  int lengthOfLIS(vector<int> &nums)
  {
    vector<vector<int>> mem1(nums.size() + 1, vector<int>(nums.size() - 1, -1));
    vector<vector<int>> mem2(nums.size() + 1, vector<int>(1, -1));

    // make that to be 0 for mem[arr.size()][i]...
    for (int i = 0; i < nums.size() - 1; i++)
    {
      mem1[nums.size()][i] = 0;
    }
    mem2[nums.size()][0] = 0;

    return helperFunc(nums, 0, -100000, mem1, mem2);
  }
};