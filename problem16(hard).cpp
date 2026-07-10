#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
  void minWindow(string s, string t)
  {
    int low = 0;
    int high = 0;
    int resultLow = 0;
    int resultHigh = 0;
    int len = INT_MAX;
    map<char, int> count;
    map<char, int> count2;
    for (int i = 0; i < t.size(); i++)
    {
      count[t[i]]++;
    }
    if (s.size() != 0)
    {
      while (low <= high && high < s.size())
      {
        if (count[s[high]] != 0)
        {
          count2[s[high]]++; // add that value in count2, as we need it in our substring
        }

        for (auto it = count.begin(); it != count.end();)
        {
          if (it->second == 0)
            it = count.erase(it); // erase returns next iterator
          else
            ++it;
        }

        for (auto it = count2.begin(); it != count2.end();)
        {
          if (it->second == 0)
            it = count2.erase(it); // erase returns next iterator
          else
            ++it;
        }
        if (count.size() == count2.size())
        {
          int length = high - low + 1;
          if (length < len)
          {
            len = length;
            cout << length << endl;
            resultLow = low;
            resultHigh = high;
          }

          while (count2[s[low]] == 0)
          {
            low++;
          }
          count2[s[low]]--;
          if (count2[s[low]] == 0)
          {
            count2.erase(s[low]);
          }

          while (count2[s[low]] == 0)
          {
            low++;
          }
        }
        else
        {
          high++;
        }
      }
      // cout << resultLow << " , " << resultHigh << endl;
    }
    else
    {
      cout << "";
    }
  }
};

int main()
{
  Solution s1;
  string s = "ADOBECODEBANC";
  string t = "ABC";
  s1.minWindow(s, t);
}