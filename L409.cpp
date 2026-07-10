#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int longestPalindrome(string s)
  {
    unordered_map<char, int> m;
    for (int i = 0; i < s.size(); i++)
    {
      m[s[i]]++;
    }

    int oddLengthedPalindrome = 0;
    int evenLengthedPalindrome = 0;
    // firstly we would like to find the odd lengthed palindrome
    int maxOdd = INT_MIN;
    for (auto i : m)
    {
      if (maxOdd < i.second && i.second % 2 != 0)
      {
        maxOdd = i.second;
      }
    }

    for (auto i : m)
    {
      if (i.second == maxOdd)
      {
        m.erase(i.first);
        break;
      }
    }

    for (auto i : m)
    {
      if (i.second % 2 == 0)
      {

        oddLengthedPalindrome += i.second;
        evenLengthedPalindrome += i.second;
      }
      else
      {
        oddLengthedPalindrome += i.second - 1;
      }
    }
    oddLengthedPalindrome += maxOdd;

    return max(oddLengthedPalindrome, evenLengthedPalindrome);
  }
};

int main()
{
  Solution s1;
  cout << s1.longestPalindrome("abccccdd");
}