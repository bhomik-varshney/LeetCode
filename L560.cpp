#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    unordered_map<int, int> m;
    int sum = 0;
    int res = 0;
    m[0] = 1;
    for (int i = 0; i < nums.size(); i++)
    {
      sum += nums[i];
      int ques = sum - k;
      int freq = m[ques];
      res += freq;
      m[sum]++;
    }
    return res;
  }
};

int main()
{
  Solution s1;
  vector<int> v = {1, 2, 3};
  cout << s1.subarraySum(v, 3);
}