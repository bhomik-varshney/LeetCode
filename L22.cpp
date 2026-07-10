#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
  void helperFunc(int &n, int &open, int &close, string &temp, vector<string> &res)
  {
    if (open == n && close == n)
    {
      // print the result...
      res.push_back(temp);
      return;
    }

    if (open < n && close == open)
    {
      // ensure that close is also less than open
      // add an open bracket...
      int new_open = open + 1;
      temp.push_back('(');
      helperFunc(n, new_open, close, temp, res); // aage ke sab dekh liye...
      temp.pop_back();                           // time to pop it back...
    }
    if (open < n && close < open)
    {
      int new_open = open + 1;
      temp.push_back('(');
      helperFunc(n, new_open, close, temp, res);
      temp.pop_back();

      int new_close = close + 1;
      temp.push_back(')');
      helperFunc(n, open, new_close, temp, res);
      temp.pop_back();
    }
    if (open == n && close < open)
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
  vector<string> res = s1.generateParenthesis(7);
  cout << res.size() << endl;
}