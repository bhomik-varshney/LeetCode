#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int findPeakElement(vector<int> &nums)
  {
    if (nums.size() != 0)
    {
      int peak = nums[0];
      int res = 0;
      for (int i = 1; i < nums.size(); i++)
      {
        if (nums[i] >= peak)
        {
          peak = nums[i];
          res = i;
        }
        else
        {
          break;
        }
      }

      return res;
    }
    else
    {
      return -1;
    }
  }

  int findPeakElement2(vector<int> &nums)
  {
    if (nums.size() != 0)
    {
      int low = 0;
      int high = nums.size() - 1;
      int peak = INT_MIN;
      int res = -1;
      while (high > low)
      {
        int mid = (high + low) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
        {
          peak = nums[mid];
          res = mid;
          break;
        }
        else if (nums[mid] > nums[mid + 1] && nums[mid] < nums[mid - 1])
        {
          high = mid;
        }
        else if (nums[mid] < nums[mid + 1] && nums[mid] > nums[mid - 1])
        {
          low = mid;
        }
      }

      return res;
    }
    else
    {
      return -1;
    }
  }
};

int main()
{
  Solution s1;
  vector<int> v = {1, 2, 3, 2, 1, 1, 1, 1, 0, 0, 0};
  cout << s1.findPeakElement(v);
}