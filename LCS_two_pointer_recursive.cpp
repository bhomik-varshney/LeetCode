#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool inText2(string text2, string subsequence)
  {
    int i = 0;
    int j = 0;

    while (j < subsequence.size() && i < text2.size())
    {
      if (text2[i] == subsequence[j])
      {
        // just increase both i and j..
        i++;
        j++;
      }
      else
      {
        // if they are not equal, means.. just increase i only..
        i++;
      }
    }

    if (j == subsequence.size())
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  int helperFunc(string &text1, string &text2, int i, int j)
  {
    if (i == text1.size() || j == text2.size())
    {
      return 0; // no subsequence could be found...
    }

    // now if they are not..
    char c1 = text1[i];
    char c2 = text2[j];
    if (c1 == c2)
    {
      // means we can take it... and move furthur...
      return 1 + helperFunc(text1, text2, i + 1, j + 1);
    }
    else
    {
      // we can not take it and check possibility for i and j as well.
      int a2 = helperFunc(text1, text2, i + 1, j);
      int a3 = helperFunc(text1, text2, i, j + 1);
      return max(a2, a3);
    }
  }

  int longestCommonSubsequence(string text1, string text2)
  {
    return helperFunc(text1, text2, 0, 0);
  }
};