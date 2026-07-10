#include <iostream>
#include <utility>
#include <stack>
using namespace std;

class Solution
{
public:
  string removeDuplicates(string s, int k)
  {
    stack<pair<char, int>> st;
    for (int i = 0; i < s.size(); i++)
    {
      if (st.empty())
      {
        pair<char, int> p1 = {s[i], 1};
        st.push(p1);
      }
      else
      {
        if (st.top().first == s[i])
        {
          st.top().second++;
        }
        else
        {
          pair<char, int> p2 = {s[i], 1};
          st.push(p2);
        }
      }

      // check whether the count value for the top character is equal to k, if yes, then simply pop that.
      if (st.top().second == k)
      {
        st.pop();
      }
    }
    int size = st.size();

    stack<pair<char, int>> st2;
    for (int i = 0; i < size; i++)
    {
      st2.push(st.top());
      st.pop();
    }
    string res;
    while (!st2.empty())
    {
      char first = st2.top().first;
      int second = st2.top().second;
      for (int j = 0; j < second; j++)
      {
        res.push_back(first);
      }
      st2.pop();
    }
    return res;
  }
};

int main()
{
  Solution s1;
  string s = "abcd";
  int k = 2;
  string result = s1.removeDuplicates(s, k);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i];
  }
}