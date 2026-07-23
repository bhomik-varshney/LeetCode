#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    int maxProduct = 1;
    int minProduct = 1;
    int res = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
      // now see ..
      int v1 = nums[i];
      int v2 = nums[i] * maxProduct;
      int v3 = nums[i] * minProduct;
      res = max(res, max(v1, max(v2, v3)));
      maxProduct = max(v1, max(v2, v3));
      minProduct = min(v1, min(v2, v3));
    }

    return res;
  }
};