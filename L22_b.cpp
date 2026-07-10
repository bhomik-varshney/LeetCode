#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
  bool valid_sequence(string temp)
  {
    stack<char> st;
    for (int i = 0; i < temp.size(); i++)
    {
      if (temp[i] == '(')
      {
        st.push(temp[i]);
      }
      if (temp[i] == ')')
      {
        if (!st.empty() && st.top() == '(')
        {
          st.pop();
        }
        else
        {
          return false;
        }
      }
    }

    return st.empty();
  }
  void helperFunc(int &n, int open, int close, string &temp, vector<string> &res)
  {
    if (open == n && close == n)
    {
      // print the result...
      if (valid_sequence(temp))
      {
        res.push_back(temp);
      }
      return;
    }

    // now simply add the open bracket and find the possible comination and then pop it...
    if (open < n)
    {
      int new_open = open + 1;
      temp.push_back('(');
      helperFunc(n, new_open, close, temp, res);
      temp.pop_back();
    }

    if (close < n)
    {
      int new_close = close + 1;
      temp.push_back(')');
      helperFunc(n, open, new_close, temp, res);
      temp.pop_back();
    }
  }

  vector<string> generateParenthesis(int n)
  {
    // backtracking will generate all possible combination for it..
    // and what ever is generated set of string, if it is a valid sequence it is appended into the answer..
    int open = 0;
    int close = 0;
    string temp;
    vector<string> res;
    helperFunc(n, open, close, temp, res);
    return res;

    // if we add ")", and check if the pair is valid ?
    // if valid , decrease the n by 1,
    // otherwise add "("
  }
};

int main()
{
  Solution s1;
  vector<string> res = s1.generateParenthesis(2);
  cout << res.size() << endl;
}