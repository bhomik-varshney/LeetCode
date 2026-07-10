#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int modulusFunc(int a)
  {
    if (a < 0)
    {
      return -a;
    }
    else
    {
      return a;
    }
  }
  int threeSumClosest(vector<int> &nums, int target)
  {
    int diff = INT_MAX;
    int result;
    sort(nums.begin(), nums.end());
    for (int k = 0; k < nums.size() - 2; k++)
    {
      int i = k + 1;
      int j = nums.size() - 1;
      int newTarget = target - nums[k];

      while (i < j)
      {

        int best_sum = nums[i] + nums[j] + nums[k];
        int sum = nums[i] + nums[j];
        if (sum < newTarget)
        {
          if (modulusFunc(target - best_sum) < diff)
          {
            diff = modulusFunc(target - best_sum);
            result = best_sum;
          }
          i++;
        }
        else if (sum > newTarget)
        {
          if (modulusFunc(target - best_sum) < diff)
          {
            diff = modulusFunc(target - best_sum);
            result = best_sum;
          }
          j--;
        }
        else
        {
          i++;
          j--;
          diff = 0;
          result = target;
        }
      }
    }

    return result;
  }
};

int main()
{
  Solution s1;
  vector<int> v = {10, 20, 30, 40, 50, 60, 70, 80, 90};
  int result = s1.threeSumClosest(v, 1);
  cout << result;
}