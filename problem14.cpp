#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
  int calcMaxCount(map<char, int> c)
  {
    int max = INT_MIN;
    int result = -1;
    for (auto i : c)
    {
      if (i.second > max)
      {
        max = i.second;
        result = i.first;
      }
    }
    return result;
  }
  int characterReplacement(string s, int k)
  {
    int low = 0;
    int high = 0;
    int result = 0;
    map<char, int> count;
    if (s.size() != 0)
    {
      count[s[high]]++;
      while (low <= high && high < s.size())
      {
        int maxCount = count[calcMaxCount(count)];
        int len = high - low + 1;
        int diff = len - maxCount;

        if (diff > k)
        {
          count[s[low]]--;
          if (count[s[low]] == 0)
          {
            count.erase(s[low]);
          }
          low++;
        }
        else
        {
          int val = high - low + 1;
          if (val > result)
          {
            result = val;
          }
          count[s[++high]]++;
        }
      }
      return result;
    }
    else
    {
      return 0;
    }
  }
};

int main()
{
  Solution s1;
  string s = "ABAB";
  cout << s1.characterReplacement(s, 2) << endl;
}