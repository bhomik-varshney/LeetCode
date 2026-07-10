#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int totalSum(vector<int> nums)
  {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      ans += nums[i];
    }
    return ans;
  }
  int maxSubarraySumCircular(vector<int> &nums)
  {
    int max_ending = nums[0];
    int min_ending = nums[0];
    int ans1 = nums[0];
    int ans2 = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
      max_ending = max(max_ending + nums[i], nums[i]);
      min_ending = min(min_ending + nums[i], nums[i]);
      ans1 = max(ans1, max_ending);
      ans2 = min(ans2, min_ending);
    }
    cout << ans1 << " , " << ans2 << endl;
    cout << totalSum(nums) << endl;
    if (totalSum(nums) != ans2)
    {
      return max(ans1, totalSum(nums) - ans2);
    }
    else
    {
      return ans1;
    }
  }
};

int main()
{
  Solution s1;
  vector<int> v = {-3, -2, -3};
  cout << s1.maxSubarraySumCircular(v);
}