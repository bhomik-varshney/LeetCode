#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int subarraysDivByK(vector<int> &nums, int k)
  {
    unordered_map<int, int> m;
    m[0] = 1;
    int sum = 0;
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      sum += nums[i];
      int ques = sum % k;

      if (ques < 0)
      {
        ques = ques + k;
      }

      int freq = m[ques];
      res += freq;
      m[ques]++;
    }

    return res;
  }
};

int main()
{
  vector<int> v = {-1, 2, 9};
  Solution s1;
  cout << s1.subarraysDivByK(v, 2) << endl;
}
