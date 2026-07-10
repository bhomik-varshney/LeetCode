#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int helperFunc(vector<int> &nums, int currHouse, bool lastRobbed, int n, vector<vector<int>> &mem)
  {
    if (currHouse == n && !lastRobbed)
    {
      // we can rob it...
      return nums[currHouse];
    }
    if (currHouse == n && lastRobbed)
    {
      // we can not rob it..
      return 0;
    }
    int idx2 = lastRobbed;
    if (mem[currHouse][idx2] != -1)
    {
      return mem[currHouse][idx2];
    }

    if (lastRobbed)
    {
      // we can not rob it...
      bool newLastRobbed = !lastRobbed;
      int a = helperFunc(nums, currHouse + 1, newLastRobbed, n, mem);
      mem[currHouse][lastRobbed] = a;
      return a;
    }
    else
    {
      // we can either rob it or not rob it..
      bool newLastRobbed = !lastRobbed;
      int a1 = helperFunc(nums, currHouse + 1, newLastRobbed, n, mem) + nums[currHouse];
      int a2 = helperFunc(nums, currHouse + 1, lastRobbed, n, mem);
      int res = max(a1, a2);
      mem[currHouse][idx2] = res;
      return res;
    }
  }

  int rob(vector<int> &nums)
  {
    int n = nums.size() - 1;
    bool lastRobbed = false;
    int currHouse = 0;
    vector<vector<int>> mem(110, vector<int>(2, -1)); // {currHouse, lastRobbed} -> ans
    return helperFunc(nums, currHouse, lastRobbed, n, mem);
  }
};