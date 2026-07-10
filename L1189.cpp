#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  int maxNumberOfBalloons(string text)
  {
    unordered_map<char, int> m;
    for (int i = 0; i < text.size(); i++)
    {
      m[text[i]]++;
    }
    int res = min(m['b'], m['a']);
    res = min(res, m['n']);
    while (res > 0)
    {
      if (m['b'] >= res && m['a'] >= res && m['n'] >= res && m['l'] >= 2 * res && m['o'] >= 2 * res)
      {
        break;
      }
      else
      {
        res--;
      }
    }
    return res;
  }
};

int main()
{
  Solution s1;
  cout << s1.maxNumberOfBalloons("balllllllllllloooooooooon") << endl;
}
