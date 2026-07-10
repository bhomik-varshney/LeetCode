#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
  int findMaxLength(vector<int> &nums)
  {
    unordered_map<int, int> m;
    int zero = 0;
    int one = 0;
    int res = 0;
    m[0] = -1; // at the start when i = -1, zero = 0, one = 0 then this diff will be stored m[0] = -1(index)
    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == 0)
      {
        zero++;
      }
      if (nums[i] == 1)
      {
        one++;
      }
      int ques = zero - one;       // in this difference is the question...
      if (m.find(ques) == m.end()) // it returns an iterator, if the key is not found, it will give end value, it could be used to find whether that key is there or not
      {
        m[ques] = i;
      }
      else
      {
        int len = i - m[ques];
        res = max(res, len);
      }
    }
    return res;
  }
};

int main()
{

  vector<int> v = {0, 0, 1};
  Solution s1;
  cout << s1.findMaxLength(v);
}