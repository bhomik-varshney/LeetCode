#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int findUnsortedSubarray(vector<int> &nums)
  {
    // find the right end boundary point, i
    if (nums.size() == 1)
    {
      return 0;
    }
    int i = 0;
    int endIdx = 0;
    int greater = nums[0];
    while (i < nums.size())
    {
      if (nums[i] >= greater)
      {
        greater = nums[i];
        i++;
      }
      else
      {
        // this one would be the rightEnd...
        endIdx = i;
        i++;
      }
    }
    int j = nums.size() - 1;
    int lesser = nums[j];
    int startIdx = nums.size() - 1;
    while (j >= 0)
    {
      if (nums[j] <= lesser)
      {
        lesser = nums[j];
        j--;
      }
      else
      {
        startIdx = j;
        j--;
      }
    }

    int size = endIdx - startIdx + 1;
    if (size < 0)
    {
      return 0;
    }
    else
    {
      return size;
    }
  }
};