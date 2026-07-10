#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  bool contains(string &s1, string &s2)
  {
    for (int i = 0; i < s2.size(); i++)
    {
      if (s2[i] == s1[0])
      {
        int idx = i;
        // now start checking from there...
        for (int j = 1; j < s1.size(); j++)
        {
          if (s2[idx + 1] == s1[j])
          {
            idx++;
          }
          else
          {
            break;
          }
        }

        if (idx == i + s1.size() - 1)
        {
          return true;
        }
      }
    }

    return false;
  }

  void permute(string &s2, int &size, unordered_map<char, int> &map, string &temp, bool &res)
  {
    if (size == 0)
    {
      // check it now...
      if (contains(temp, s2))
      {
        res = true;
        return;
      }
      else
      {
        return;
      }
    }
    else
    {
      for (auto &i : map)
      {
        char c = i.first;
        int freq = i.second;

        // now find the answer for it as well..
        if (freq > 0)
        {
          temp.push_back(c);
          size--;
          // means we can use that...
          i.second--;

          permute(s2, size, map, temp, res);
          // reverting back the changes

          map[c]++;
          size++;
          temp.pop_back();
        }
      }
      return;
    }
  }

  bool checkInclusion(string s1, string s2)
  {
    unordered_map<char, int> map;
    for (int i = 0; i < s1.size(); i++)
    {
      map[s1[i]]++;
    }
    string temp;
    bool res = false;
    int size = s1.size();
    permute(s2, size, map, temp, res);
    return res;
  }
};