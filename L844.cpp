#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
  bool backspaceCompare(string s, string t)
  {
    stack<char> st1;
    stack<char> st2;
    int i = 0;
    int j = 0;
    while (i < s.size() && j < t.size())
    {
      if (s[i] != '#')
      {
        st1.push(s[i]);
      }
      else
      {
        if (!st1.empty())
        {
          st1.pop();
        }
      }

      if (t[j] != '#')
      {
        st2.push(t[j]);
      }
      else
      {
        if (!st2.empty())
        {
          st2.pop();
        }
      }

      i++;
      j++;
    }

    while (i < s.size())
    {
      if (s[i] != '#')
      {
        st1.push(s[i]);
      }
      else
      {
        if (!st1.empty())
        {
          st1.pop();
        }
      }
      i++;
    }

    while (j < t.size())
    {
      if (t[j] != '#')
      {
        st2.push(t[j]);
      }
      else
      {
        if (!st2.empty())
        {
          st2.pop();
        }
      }
      j++;
    }

    string output1;
    string output2;

    while (!st1.empty())
    {
      output1.push_back(st1.top());
      st1.pop();
    }
    while (!st2.empty())
    {
      output2.push_back(st2.top());
      st2.pop();
    }

    cout << output1 << endl;
    cout << output2 << endl;

    if (output1 == output2)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

// time complexity would be O(n) ; where n = max(s.size(),t.size())
// space complexity would be O(n+m)