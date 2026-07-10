#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> nextGreaterElements(vector<int> &nums)
  {
    // we have the circular array it means i = (i+1)%n, where n is the size of the array
    vector<int> res;
    stack<int> st;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
      st.push(nums[i]);
    }
    // we have pushed the values in the stack 3,2,1,0 if we have 5 size array.
    for (int i = nums.size() - 1; i >= 0; i--)
    {
      while (!st.empty() && st.top() <= nums[i])
      {
        st.pop();
      }
      if (st.empty())
      {
        res.push_back(-1);
      }
      else
      {
        res.push_back(st.top());
      }
      st.push(nums[i]);
    }
    vector<int> res2;
    stack<int> st2;
    for (int i = 0; i < res.size(); i++)
    {
      st2.push(res[i]);
    }
    while (!st2.empty())
    {
      res2.push_back(st2.top());
      st2.pop();
    }
    return res2;
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