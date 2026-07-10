#include <iostream>
using namespace std;

class Solution
{
public:
  // we have string s = "abcde", and words = ["a","bb","acd","ace"], if word[i] is the subsequence of s, then add it to the result, return number of subsequence value
  int subsequences(string s, vector<string> words)
  {
    int res = 0;
    for (int i = 0; i < words.size(); i++)
    {
      string subsequenceToFind = words[i];
      int pointer1 = 0;
      int pointer2 = 0;
      while (pointer1 < subsequenceToFind.size() && pointer2 < s.size())
      {
        if (subsequenceToFind[pointer1] == s[pointer2])
        {
          pointer1++;
        }
        pointer2++;
      }
      if (pointer1 == subsequenceToFind.size())
      {
        res++;
      }
    }

    return res;
  }
};

int main()
{
  vector<string> words = {"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"};
  string s = "";
  Solution s1;
  cout << s1.subsequences(s, words);
}