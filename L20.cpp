#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
  bool isValid(string s) // this is the optimised approach where time complexity is O(n) and space complexity is O(n)
  {
    // we contain the brackets as "()", "[]" and "{}"
    char opening1 = '(';
    char opening2 = '{';
    char opening3 = '[';

    char closing1 = ')';
    char closing2 = '}';
    char closing3 = ']';
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
      if (s[i] == opening1 || s[i] == opening2 || s[i] == opening3)
      {
        st.push(s[i]);
      }
      else
      {
        if (s[i] == closing1 && st.top() == opening1)
        {
          st.pop();
        }
        if (s[i] == closing2 && st.top() == opening2)
        {
          st.pop();
        }
        if (s[i] == closing3 && st.top() == opening3)
        {
          st.pop();
        }
      }
    }

    if (st.size() == 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

int main()
{
  Solution s1;
  string s = "()";
  cout << s1.isValid(s);
}