#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k)
  {
    int low = 0;
    int high = 0;
    int currProduct = 1;
    int res = 0;
    while (low <= high && high < nums.size())
    {
      currProduct = currProduct * nums[high];

      if (currProduct >= k)
      {
        while (currProduct >= k)
        {
          currProduct = currProduct / nums[low];
          low++;
        }
        high++;
      }
      else
      {
        res += high - low + 1;
        high++;
      }
    }

    return res;
  }
};