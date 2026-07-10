#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    int ans = nums[0];
    int max_ending = nums[0];
    int min_ending = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
      int option_A = max_ending * nums[i];
      int option_B = min_ending * nums[i];
      int option_C = nums[i];
      max_ending = max(option_A, option_B);
      max_ending = max(max_ending, option_C);
      min_ending = min(option_A, option_B);
      min_ending = min(min_ending, option_C);

      ans = max(ans, max_ending);
    }

    return ans;
  }
};

int main()
{
  Solution s1;
  vector<int> v = {-2, 3, -4};
  cout << s1.maxProduct(v);
}