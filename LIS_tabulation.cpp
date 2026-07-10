#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    vector<vector<int>> mem1(nums.size() + 1, vector<int>(nums.size(), -1));
    vector<vector<int>> mem2(nums.size() + 1, vector<int>(1, -1));

    // make that to be 0 for mem[arr.size()][i]...
    for (int i = 0; i < nums.size(); i++)
    {
      mem1[nums.size()][i] = 0;
    }
    mem2[nums.size()][0] = 0;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
      int index = i;
      for (int j = 0; j < nums.size(); j++)
      {
        int lastNumberIndex = j;

        if (nums[index] > nums[lastNumberIndex])
        {
          int a1 = 1 + mem1[index + 1][index];
          int a2 = mem1[index + 1][lastNumberIndex];
          mem1[index][lastNumberIndex] = max(a1, a2);
        }
        else
        {
          mem1[index][lastNumberIndex] = mem1[index + 1][lastNumberIndex];
        }
      }
    }

    // now do it for mem2...
    for (int i = nums.size() - 1; i >= 0; i--)
    {
      int index = i;
      // we always have free choice...
      int a1 = 1 + mem1[index + 1][index];
      int a2 = mem2[index + 1][0];
      mem2[index][0] = max(a1, a2);
    }

    return mem2[0][0];
  }
};