#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &nums) // this is the brute force method, time = O(n^2) , space = O(n)
  {
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
      int target = nums[i];
      int nextGreaterThanTarget = target;
      for (int j = (i + 1) % nums.size(); j != i % nums.size(); j = (j + 1) % nums.size()) // %n is used for the circular array
      {
        if (nums[j] > nextGreaterThanTarget)
        {
          nextGreaterThanTarget = nums[j];
          break;
        }
      }
      if (nextGreaterThanTarget == target)
      {
        res.push_back(-1);
      }
      else
      {
        res.push_back(nextGreaterThanTarget);
      }
    }
    return res;
  }
};

int main()
{
  Solution s1;
  vector<int> v = {1, 2, 3, 4, 3};
  vector<int> result = s1.nextGreaterElements(v);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " , ";
  }
}