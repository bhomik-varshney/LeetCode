#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
  bool backspaceCompare(string s, string t)
  {
    int i = s.size() - 1;
    int j = t.size() - 1;
    int skip1 = 0;
    int skip2 = 0;
    while (i >= 0 || j >= 0)
    {
      // find the i that could survive...
      while (i >= 0)
      {
        if (s[i] == '#')
        {
          i--;
          skip1++;
        }
        else if (skip1 > 0)
        {
          i--;
          skip1--;
        }
        else
        {
          break;
        }
      }

      while (j >= 0)
      {
        if (t[j] == '#')
        {
          j--;
          skip2++;
        }
        else if (skip2 > 0)
        {
          j--;
          skip2--;
        }
        else
        {
          break;
        }
      }

      // now we are the right position...
      if (i >= 0 && j >= 0)
      {
        // check it...
        if (s[i] != t[j])
        {
          return false;
        }
        else
        {
          i--;
          j--;
        }
      }
      else if (i < 0 && j >= 0)
      {
        return false;
      }
      else if (i >= 0 && j < 0)
      {
        return false;
      }
    }

    return true;
  }
};