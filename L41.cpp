#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int firstMissingPositive(vector<int> &nums)
  {
    // using cyclic sorting
    int i = 0;
    while (i < nums.size())
    {
      long long num = nums[i];
      long long idx = i;
      // check if it is in correct position or not...
      if (idx == num - 1)
      {
        // simply go beyond...
        i++;
      }
      else
      {
        long long corrPos = num - 1;
        // check if index exists or not in the nums...
        if (corrPos >= 0 && corrPos < nums.size() && nums[corrPos] != num) // means num is not already present at that particular index..
        {
          // just simply swap it with that number...
          long long num2 = nums[corrPos];
          nums[idx] = num2;
          nums[corrPos] = num;
        }
        else
        {
          // just simply increase the i
          i++;
        }
      }
    }

    // now check it...
    for (int i = 0; i < nums.size(); i++)
    {
      int num = nums[i];
      int idx = i;
      if (num == idx + 1)
      {
        // no problem..
        continue;
      }
      else
      {
        return idx + 1;
      }
    }
    return nums.size() + 1;
  }
};