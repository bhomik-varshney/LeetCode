#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

class Solution
{
public:
  vector<int> dailyTemperatures(vector<int> &temperatures)
  // we have to simply find the next greater element and just return the index value for it
  {
    vector<int> res;
    res.push_back(0);
    stack<pair<int, int>> st;
    pair<int, int> p1 = {temperatures[temperatures.size() - 1], temperatures.size() - 1};
    st.push(p1);
    for (int i = temperatures.size() - 2; i >= 0; i--)
    {
      while (!st.empty() && st.top().first <= temperatures[i])
      {
        st.pop();
      }
      if (st.empty())
      {
        res.push_back(0);
      }
      else
      {
        res.push_back(st.top().second - i);
      }
      pair<int, int> p2 = {temperatures[i], i};
      st.push(p2);
    }

    // we will get the inverted value , but now we have to again reverse the array, so we will use another stack to do it.
    stack<int> dupSt;
    for (int i = 0; i < res.size(); i++)
    {
      dupSt.push(res[i]);
    }
    // now overwrite these values into the res2
    vector<int> res2;
    int size = dupSt.size();
    for (int i = 0; i < size; i++)
    {
      int topVal = dupSt.top();
      res2.push_back(topVal);
      dupSt.pop();
    }

    return res2;
  }
};

int main()
{
  Solution s1;
  vector<int> v = {73, 74, 75, 71, 69, 72, 76, 73};
  vector<int> res = s1.dailyTemperatures(v);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
}