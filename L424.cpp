#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int maxCount(unordered_map<char, int> &map)
  {
    int res = 0;
    for (auto i : map)
    {
      res = max(res, i.second);
    }
    return res;
  }

  int characterReplacement(string s, int k)
  {
    int low = 0;
    int high = 0;
    unordered_map<char, int> map;
    int res = 1;
    map[s[high]]++;
    while (low <= high && high < s.size())
    {
      // after addinh high value, see the length of the hashmap...
      if (map.size() > 1)
      {
        // now simply see the maxCount...
        int currLen = high - low + 1;
        int maxFreq = maxCount(map);
        int diff = currLen - maxFreq;
        if (diff > k)
        {
          // we have to shrink the window...
          map[s[low]]--;
          if (map[s[low]] == 0)
          {
            map.erase(s[low]);
          }
          low++;
        }
        else
        {
          res = max(res, high - low + 1);
          high++;
          if (high < s.size())
          {
            map[s[high]]++;
          }
        }
      }
      else
      {
        // no problem, just increase high value..
        res = max(res, high - low + 1);
        high++;
        if (high < s.size())
        {
          map[s[high]]++;
        }
      }
    }

    return res;
  }
};