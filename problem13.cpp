#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int low = 0;
    int high = 0;
    map<char, int> count;
    int result = 0;
    count[s[high]]++;
    if (s.size() != 0)
    {
      while (low <= high && high < s.size())
      {
        if (check(count))
        {
          if (result < (high - low + 1))
          {
            result = (high - low + 1);
          }
          if (high < s.size())
          {
            high++;
            count[s[high]]++;
          }
        }
        else
        {
          count[s[low]]--;
          if (count[s[low]] == 0)
          {
            count.erase(s[low]);
          }
          low++;
        }
      }
      return result;
    }
    else
    {
      return 0;
    }
  }

  bool check(map<char, int> c)
  {
    for (auto x : c)
    {
      if (x.second != 1)
      {
        return false;
        break;
      }
    }
    return true;
  }
};

int main()
{
  Solution s1;
  string s = "pwwkew";
  cout << s1.lengthOfLongestSubstring(s) << endl;
}