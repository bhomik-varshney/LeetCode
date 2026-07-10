#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int helperFunc(vector<int> &nums, int index, int lastNumber)
  {
    if (index == nums.size())
    {
      return 0;
    }
    // if index != nums.size()-1;
    // if the index is not the last one. just calculate if we take that, or not we have taken it...
    if (nums[index] > lastNumber)
    {
      // taking it..
      int a1 = 1 + helperFunc(nums, index + 1, nums[index]);

      // not taking it..
      int a2 = helperFunc(nums, index + 1, lastNumber);

      return max(a1, a2);
    }
    else
    {
      return helperFunc(nums, index + 1, lastNumber);
    }
  }

  int lengthOfLIS(vector<int> &nums)
  {
    return helperFunc(nums, 0, -100000);
  }
};