#include <iostream>
using namespace std;

class Solution
{
public:
  bool isPalindrome(string &s)
  {
    // code here
    int len = s.size();
    if (len == 1 || len == 0)
    {
      return true;
    }
    if (s[0] == s[len - 1])
    {
      string newString = s.substr(1, len - 2);
      return isPalindrome(newString);
    }
    else
    {
      return false;
    }
  }
};

int main()
{
  string s = "abdcba";
  Solution s1;
  cout << s1.isPalindrome(s);
}