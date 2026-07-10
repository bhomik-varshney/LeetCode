#include <iostream>
#include <utility>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  int firstUniqChar(string s)
  {
    // it must have t -> (x,y), t is the character, x is the first time it got seen, and the y is the number of times we saw it...
    unordered_map<char, pair<int, int>> m;
    for (int i = 0; i < s.size(); i++)
    {
      if (m[s[i]].second == 0)
      {
        m[s[i]].first = i;
        m[s[i]].second += 1;
      }
      else
      {
        m[s[i]].second += 1;
      }
    }
    // now, we will find which key has the minimum x value and y value to be 1.....
    int minXValue = INT_MAX;
    for (int i = 0; i < m.size(); i++)
    {
      if (m[i].second == 1 && m[i].first < minXValue)
      {
        minXValue = m[i].first;
      }
    }

    if (minXValue == INT_MAX)
    {
      return -1;
    }
    else
    {
      return minXValue;
    }
  }
};

int main()
{
  Solution s1;
  cout << s1.firstUniqChar("leetcode");
}