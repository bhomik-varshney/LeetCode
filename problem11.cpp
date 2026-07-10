#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
  // int cntDistinct(string str, int low, int high) // //you can also use this function, but time complexity will increase
  // {
  //   map<char, int> count;
  //   for (int i = low; i <= high; i++)
  //   {
  //     count[str[i]]++;
  //   }
  //   return count.size();
  // }

  int longestKSubstr(string &s, int k)
  {
    // code here
    int low = 0;
    int high = 0;
    int distinct = 0;
    int result = -1;
    map<char, int> count;
    if (s.size() != 0)
    {
      while (high < s.size() && high >= low)
      {
        if (low == 0 && high == 0)
        {
          distinct = 1;
          count[s[low]]++;
        }
        else
        {
          distinct = count.size();
        }

        if (distinct < k)
        {
          high++;
          count[s[high]]++;
        }
        else if (distinct > k)
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
          int len = high - low + 1;
          result = max(result, len);
          high++;
          count[s[high]]++;
        }
      }

      return result;
    }
    else
    {
      return -1;
    }
  }
};

int main()
{
  Solution s1;
  string s = "aabacbebebe";
  int k = 3;
  cout << s1.longestKSubstr(s, k) << endl;
}