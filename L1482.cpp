#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int findMax(vector<int> &nums)
  {
    int maxNum = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
      maxNum = max(maxNum, nums[i]);
    }
    return maxNum;
  }

  bool findPossibility(vector<int> &nums, int &m, int &k, int &val)
  {
    // check its possible to wait for val days, and then able to make m bouquets...
    // k adjacent flowers are also needed....
    // use sliding window for that...
    int flowers = 0;
    int bouq = 0;

    for (auto i : nums)
    {
      if (i <= val)
      {
        flowers++;
        if (flowers == k)
        {
          bouq++;
          flowers = 0;
        }
      }
      else
      {
        flowers = 0;
      }
    }

    if (bouq >= m)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  int minDays(vector<int> &bloomDay, int m, int k)
  {
    // bloomDay -> arr, m, k -> int
    // we need to make sure that, nums.size() >= m * k

    // return minimum days to wait to be able to make m bouquets from tne garden

    int res = INT_MAX;
    // we could have options is to wait for 0 days, and maximum is to wait is the maximum of nums.size()...

    int low = 0;
    int high = findMax(bloomDay);

    while (low <= high)
    {
      int mid = low + ((high - low) / 2);
      cout << "mid value : " << mid << endl;
      // find if its possible to make m bouquets or not (done already)
      bool possible = findPossibility(bloomDay, m, k, mid);

      if (possible)
      {
        res = min(res, mid);
        cout << mid << endl;
        // search for new best possible answer...
        high = mid - 1;
      }
      else
      {
        // search for more..
        low = mid + 1;
      }
    }
    if (res == INT_MAX)
    {
      return -1;
    }
    else
    {
      return res;
    }
  }
};