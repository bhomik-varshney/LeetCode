#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int findProduct(vector<int> &nums, int low, int high)
  {
    int res = 1;
    for (int i = low; i <= high; i++)
    {
      res *= nums[i];
    }
    return res;
  }

  int helperFunc(vector<int> &nums, int low, int high)
  {
    if (low > high || high == nums.size())
    {
      return -10;
    }

    // find the product value....
    int a1 = findProduct(nums, low, high);
    int a2 = helperFunc(nums, low + 1, high);
    int a3 = helperFunc(nums, low, high + 1);

    return max(a1, max(a2, a3));
  }

  int maxProduct(vector<int> &nums)
  {
    // find all possibilities of product of a subarray...
    return helperFunc(nums, 0, 0);
  }
};