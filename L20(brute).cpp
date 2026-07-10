#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
  bool isValid(string s) // this is the brute force method solve this question, it takes O(n^2) time complexity and O(n) space complexity
  {
    // we contain the brackets as "()", "[]" and "{}"
    char opening1 = '(';
    char opening2 = '{';
    char opening3 = '[';

    char closing1 = ')';
    char closing2 = '}';
    char closing3 = ']';
    string res = s;
    if (res.size() != 0)
    {
      for (int count = 0; count < s.size(); count++)
      {
        string onePass;
        for (int i = 0; i < res.size(); i++)
        {
          if (res[i] == opening1)
          {
            // check whether the next one is closing one or not, if yes then remove it, otherwise add that into new string
            if ((i + 1) < res.size() && res[i + 1] == closing1)
            {
              i++;
            }
            else
            {
              onePass.push_back(res[i]);
            }
          }
          else if (res[i] == opening2)
          {
            // check whether the next one is closing one or not, if yes then remove it, otherwise add that into new string
            if ((i + 1) < res.size() && res[i + 1] == closing2)
            {
              i++;
            }
            else
            {
              onePass.push_back(res[i]);
            }
          }
          else if (res[i] == opening3)
          {
            // check whether the next one is closing one or not, if yes then remove it, otherwise add that into new string
            if ((i + 1) < res.size() && res[i + 1] == closing3)
            {
              i++;
            }
            else
            {
              onePass.push_back(res[i]);
            }
          }
          else
          {
            onePass.push_back(res[i]);
          }
        }
        res = onePass;
      }
    }
    else
    {
      return true;
    }
    // cout << res.size() << endl;
    if (res.size() == 0)
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
  string s = "(";
  cout << s1.isValid(s);
}