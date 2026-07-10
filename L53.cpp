#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int best_ending = nums[0];
    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
      int option_A = best_ending + nums[i];
      int option_B = nums[i];
      best_ending = max(option_A, option_B);
      ans = max(best_ending, ans);
    }

    return ans;
  }
};

int main()
{
  Solution s1;
  vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << s1.maxSubArray(v);
}
