#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  bool checkEquality(unordered_map<char, int> &map1, unordered_map<char, int> &map2)
  {
    for (auto i : map1)
    {
      char targetChar = i.first;
      int targetFreq = i.second;

      if (map2.find(targetChar) != map2.end())
      {
        // if we have found out, check if it has same freq or more....
        if (map2[targetChar] < targetFreq)
        {
          return false;
        }
        else
        {
          continue;
        }
      }
      else
      {
        return false;
      }
    }

    return true;
  }

  string minWindow(string s, string t)
  {
    unordered_map<char, int> map1;
    // store the values in map1 for t string
    for (int i = 0; i < t.size(); i++)
    {
      map1[t[i]]++;
    }

    int low = 0;
    int high = 0;
    int len = INT_MAX;
    int resultLow = -1;
    int resultHigh = -1;
    unordered_map<char, int> map2;
    map2[s[high]]++;
    while (low <= high && high < s.size())
    {
      // see if i can do this or not...
      if (map2.size() < map1.size())
      {
        // means all the characters of t are not in s...
        high++;
        if (high < s.size())
        {
          map2[s[high]]++;
        }
      }
      else
      {
        // map2.size() >= map1.size(), check if map2 has the characters to be equal in freq as well..
        int res = checkEquality(map1, map2);

        if (res)
        {
          // means we are good to go..
          // try shrinking the window...
          if (high - low + 1 < len)
          {
            len = high - low + 1;
            resultLow = low;
            resultHigh = high;
          }
          map2[s[low]]--;
          if (map2[s[low]] == 0)
          {
            map2.erase(s[low]);
          }
          low++;
        }
        else
        {
          // try to increase the value of high then..
          high++;
          if (high < s.size())
          {
            map2[s[high]]++;
          }
        }
      }
    }

    if (len != INT_MAX)
    {
      // make the string...
      string resultingString;
      for (int i = resultLow; i <= resultHigh; i++)
      {
        resultingString.push_back(s[i]);
      }
      return resultingString;
    }
    else
    {
      return "";
    }
  }
};