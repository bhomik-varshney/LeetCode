#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    vector<int> res = {-1, -1}; // default answer to be given if no interval found...
    int low = 0;
    int high = nums.size() - 1;
    int lidx = INT_MAX;
    int hidx = INT_MIN;

    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (nums[mid] < target)
      {
        // neglect all the prev values...
        low = mid + 1;
      }
      else if (nums[mid] > target)
      {
        // neglect all the upcoming values...
        high = mid - 1;
      }
      else
      {
        // if nums[mid] == target value...
        if (mid < lidx)
        {
          lidx = mid;
          high = mid - 1;
        }
      }
    }

    low = 0;
    high = nums.size() - 1;

    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (nums[mid] < target)
      {
        // neglect all the prev values...
        low = mid + 1;
      }
      else if (nums[mid] > target)
      {
        // neglect all the upcoming values...
        high = mid - 1;
      }
      else
      {
        // if nums[mid] == target value...
        if (mid > hidx)
        {
          hidx = mid;
          low = mid + 1;
        }
      }
    }

    if (lidx != INT_MAX || hidx != INT_MIN)
    {
      res[0] = lidx;
      res[1] = hidx;
      return res;
    }
    else
    {
      return res;
    }
  }
};