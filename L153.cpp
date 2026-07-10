#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int findMin(vector<int> &nums)
  {
    int res = nums[0];
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (res > nums[mid])
      {
        res = nums[mid];
        high = mid - 1;
      }
      else
      {
        low = mid + 1;
      }
    }

    return res;
  }
};