#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void helperFunc(vector<int> &nums, int index, int lastNumber, int currLength, int &res)
  {
    if (index == nums.size())
    {
      // just stop and see if the length...
      if (currLength > res)
      {
        res = currLength;
      }
      return;
    }

    // if index != nums.size(), means we can search around the index...
    if (nums[index] > lastNumber)
    {
      // means we can take it...
      helperFunc(nums, index + 1, nums[index], currLength + 1, res);

      // we also can reject it...(to see other opportunities)
      helperFunc(nums, index + 1, lastNumber, currLength, res);
    }
    else
    {
      // we can not take it...
      helperFunc(nums, index + 1, lastNumber, currLength, res);
    }

    return;
  }

  int lengthOfLIS(vector<int> &nums)
  {
    int res = 0;
    helperFunc(nums, 0, -100000, 0, res);
    return res;
  }
};