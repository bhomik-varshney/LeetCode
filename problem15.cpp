#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
  int calcMaxCount(map<int, int> count)
  {
    int result = -1;
    int max = INT_MIN;
    for (auto i : count)
    {
      if (i.second > max)
      {
        max = i.second;
        result = i.first;
      }
    }
    return result;
  }
  int longestOnes(vector<int> &nums, int k)
  {
    int low = 0;
    int high = 0;
    int result = 0;
    map<int, int> count;
    if (nums.size() != 0)
    {
      count[nums[low]]++;
      while (low <= high && high < nums.size())
      {
        int diff = count[0];
        if (diff > k)
        {
          if (low == high)
          {
            high++;
            if (high < nums.size())
            {
              count[nums[high]]++;
            }
          }
          count[nums[low]]--;
          if (count[nums[low]] == 0)
          {
            count.erase(nums[low]);
          }
          low++;
        }
        else
        {
          int val = high - low + 1;
          if (val > result)
          {
            result = val;
          }
          high++;
          if (high < nums.size())
          {
            count[nums[high]]++;
          }
        }
      }

      return result;
    }
    else
    {
      return 0;
    }
  }
};

int main()
{
  Solution s1;
  vector<int> v = {0, 0, 1, 1, 1, 0, 0};
  cout << s1.longestOnes(v, 0);
}