#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int totalSum(vector<int> nums)
  {
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      res += nums[i];
    }
    return res;
  }
  int pivotIndex(vector<int> &nums)
  {
    int prefix = 0;
    int suffix = totalSum(nums);

    for (int i = 0; i < nums.size(); i++)
    {
      if (i != 0)
      {
        prefix = prefix + nums[i - 1];
      }
      else
      {
        prefix = 0;
      }
      suffix = suffix - nums[i];
      if (prefix == suffix)
      {
        return i;
        break;
      }
    }
    return -1;
  }
};

int main()
{
  Solution s1;
  vector<int> v = {2, 1, -1};
  cout << s1.pivotIndex(v) << endl;
}