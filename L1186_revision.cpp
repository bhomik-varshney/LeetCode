#include <iostream>
#include <vectpr>
using namespace std;

class Solution
{
public:
  int maximumSum(vector<int> &nums)
  {
    // we can delete one atmost..
    int oneDelete = nums[0];
    int noDelete = nums[0];

    int res = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
      // see options as :
      // 1 . nums[i] (the only element is being taken)
      // 2. nums[i] + no delete (all the elements are being taken)
      // 3. onedelete + nums[i] (one element already deleted)
      // 4. no delete (the same element is being deleted)

      int v1 = nums[i];
      int v2 = nums[i] + noDelete;
      int v3 = nums[i] + oneDelete;
      int v4 = noDelete;

      // find maximum from it..
      res = max(res, max(v1, max(v2, max(v3, v4))));
      // change the value of oneDelete and noDelete..

      oneDelete = max(v4, v3);

      noDelete = max(v1, v2);
    }

    return res;
  }
};