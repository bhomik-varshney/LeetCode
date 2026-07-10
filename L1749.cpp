#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxAbsoluteSum(vector<int> &nums)
  {
    int min_ending = nums[0];
    int max_ending = nums[0];
    int ans = abs(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
      max_ending = max(max_ending + nums[i], nums[i]);
      min_ending = min(min_ending + nums[i], nums[i]);
      ans = max(ans, max(abs(max_ending), abs(min_ending)));  // saare ke saare max_ending , saare ke saare min_ending, ans iska maximum value lelo
    }
    return ans;
  }
};

int main()
{
  Solution s1;
  vector<int> v = {-7, -1, 0, -2, 1, 3, 8, -2, -6, -1, -10, -6, -6, 8, -4, -9, -4, 1, 4, -9};
  cout << s1.maxAbsoluteSum(v);
}


// this is what i tried :- 
// int maxAbsoluteSum(vector<int> &nums)
//   {
//     int best_ending = abs(nums[0]);
//     int ans = abs(nums[0]);
//     int val = nums[0];
//     for (int i = 1; i < nums.size(); i++)
//     {
//       best_ending = max(abs(val + nums[i]), abs(nums[i]));
//       if (abs(val + nums[i]) > abs(nums[i]))
//       {
//         val = val + nums[i];
//       }
//       else
//       {
//         val = nums[i];
//       }

//       ans = max(ans, best_ending);
//     }

//     return ans;
//   }