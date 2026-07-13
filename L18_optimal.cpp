#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    vector<vector<int>> res;
    // sort it first..
    sort(nums.begin(), nums.end());
    for (int m = 0; m < nums.size(); m++)
    {
      for (int n = m + 1; n < nums.size(); n++)
      {
        int first = nums[m];
        int second = nums[n];
        // now find the third and fourth using two pointer...
        long long newTarget = (long long)target - first - second;

        int low = n + 1;
        int high = nums.size() - 1;
        while (low < nums.size() && high > n && low < high)
        {
          // now see it as...
          int third = nums[low];
          int fourth = nums[high];
          int sum = third + fourth;
          if (sum == newTarget)
          {
            res.push_back({first, second, third, fourth});
            low++;
            high--;
          }
          else if (sum < newTarget)
          {
            // increase the low
            low++;
          }
          else
          {
            // decrease high
            high--;
          }
        }
      }
    }
    sort(res.begin(), res.end());
    if (res.size() > 1)
    {
      int i = 0;
      int j = 1;
      // we need to remove duplicacy..
      while (j < res.size())
      {
        if (res[i] == res[j])
        {
          j++;
        }
        else
        {
          i++;
          // swap both..
          vector<int> temp = res[i];
          res[i] = res[j];
          res[j] = temp;
          j++;
        }
      }
      // now from 0 to i,
      j = res.size() - 1;
      while (j != i)
      {
        res.pop_back();
        j--;
      }
    }
    return res;
  }
};