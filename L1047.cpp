#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
  void display(stack<char> st)
  {
    int size = st.size();
    for (int i = 0; i < size; i++)
    {
      cout << st.top() << " , ";
      st.pop();
    }
    cout << endl;
  }
  // this is my brute force method to solve that
  string removeDuplicates(string s) // time :- O(n^2), space :- O(2n) -> O(n)
  {
    string res = s;
    for (int count = 0; count <= (s.size() / 2) + 1; count++)
    {
      string passString;
      for (int i = 0; i < res.size(); i++)
      {
        if (i != res.size() - 1)
        {
          if (res[i] == res[i + 1])
          {
            i++;
          }
          else
          {
            passString.push_back(res[i]);
          }
        }
        else
        {
          passString.push_back(res[i]);
        }
      }

      res = passString;
    }

    return res;
  }

  // string removeDuplicates(string s) // time :- O(n), space :- O(3n) -> O(n)
  // {
  //   stack<char> st;
  //   stack<char> st2;
  //   string res;
  //   for (int i = 0; i < s.size(); i++) // O(n)
  //   {
  //     if (!st.empty())
  //     {
  //       char top = st.top();

  //       if (s[i] == top)
  //       {
  //         // pop:- we have found the duplicate values
  //         st.pop();
  //       }
  //       else
  //       {

  //         // otherwise push that element into the stack
  //         st.push(s[i]);
  //       }
  //     }
  //     else
  //     {
  //       st.push(s[i]);
  //     }
  //   }

  //   int size = st.size();

  //   for (int i = 0; i < size; i++) // O(n)
  //   {
  //     char val = st.top();
  //     st2.push(val);
  //     st.pop();
  //   }

  //   size = st2.size();
  //   for (int i = 0; i < size; i++) // O(n)
  //   {
  //     char val = st2.top();
  //     res.push_back(val);
  //     st2.pop();
  //   }
  //   return res;
  // }
};

int main()
{
  string s = "";
  Solution s1;
  string s2 = s1.removeDuplicates(s);
  for (int i = 0; i < s2.size(); i++)
  {
    cout << s2[i];
  }
}