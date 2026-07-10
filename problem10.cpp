#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int minSubArrayLen(int target, vector<int> &nums)
  {
    int low = 0;
    int high = 0;
    int result = INT_MAX;
    int val = 0;

    while (low <= high && high < nums.size())
    {
      if (low == 0 && high == 0)
      {
        val = nums[low];
      }

      if (val < target)
      {
        high++;
        val += nums[high];
      }
      else
      {

        if (result > (high - low + 1))
        {
          result = high - low + 1;
        }
        low++;
        val -= nums[low - 1];
      }
    }
    if (result == INT_MAX)
    {
      return 0;
    }
    else

    {
      return result;
    }
  }
};

int main()
{
  vector<int> v = {1, 1, 1, 1, 1, 1, 1, 1};
  Solution s1;
  int result = s1.minSubArrayLen(11, v);
  cout << result;
}