#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    int slow = 0;
    int fast = 0;
    while (true)
    {
      slow = nums[slow];
      fast = nums[nums[fast]];
      if (slow == fast)
      {
        break;
      }
    }
    cout << slow << " , " << fast << endl;
    slow = 0;
    while (slow != fast)
    {
      slow = nums[slow];
      fast = nums[fast];
    }
    return fast;
  }
};

int main()
{
  vector<int> nums = {1, 2, 3, 4, 3};
  Solution s1;
  cout << s1.findDuplicate(nums) << endl;
}