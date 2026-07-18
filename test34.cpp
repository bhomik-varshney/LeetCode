#include <iostream>
using namespace std;

class Solution
{
public:
  string encryptedMessage(int N, string S, int K)
  {
    string ans;
    if (N % K == 0)
    {
      // it means it can be made into some chunks of string...
      for (int i = 0; i < S.size(); i += K)
      {
        string chunk = S.substr(i, K);
        // but first we need to reverse it...
        reverse(chunk.begin(), chunk.end());
        ans += chunk;
      }

      return ans;
    }
    else
    {
      // now there means we have some remaining part of size < k at the end..
      int i = 0;
      while (i != S.size())
      {
        int remainingSize = N - i;
        if (remainingSize >= K)
        {
          // no problem....
          string chunk;
          chunk = S.substr(i, K);
          i += K;
          reverse(chunk.begin(), chunk.end());
          ans += chunk;
        }
        else
        {
          string chunk = S.substr(i, remainingSize);
          i += remainingSize;
          reverse(chunk.begin(), chunk.end());
          ans += chunk;
        }
      }
      return ans;
    }
  }
};

int main()
{
  Solution s1;
  string res = s1.encryptedMessage(5, "aabbz", 2);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i];
  }
}
