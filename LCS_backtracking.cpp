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

  void helperFunc(string &text1, string &text2, int idx, string currSequence, int &res)
  {
    if (idx == text1.size())
    {
      return;
    }

    // we can take this idx from text1 or either we can ignore it in our subsequence

    // 1. by taking it...
    string newString = currSequence;
    newString.push_back(text1[idx]);
    // see if that exists in text2 or not...
    if (inText2(text2, newString))
    {
      // then change the res by newString.size();
      if (res < newString.size())
      {
        res = newString.size();
      }
    }

    helperFunc(text1, text2, idx + 1, newString, res);
    helperFunc(text1, text2, idx + 1, currSequence, res);

    return;
  }

  int longestCommonSubsequence(string text1, string text2)
  {
    string currSequence;
    int res = 0;
    // currSequence.push_back(text1[0]);
    helperFunc(text1, text2, 0, currSequence, res);
    return res;
  }
};