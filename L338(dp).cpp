#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int helperFunc(int n, vector<int> &mem)
  {
    if (n == 0)
    {
      return 0;
    }

    if (mem[n] != 0)
    {
      return mem[n];
    }

    if (n % 2 == 0)
    {
      // even
      return helperFunc(n / 2, mem);
    }
    else
    {
      // odd
      return helperFunc(n - 1, mem) + 1;
    }
  }

  vector<int> countBits(int n)
  {
    vector<int> mem(n + 1, 0);
    vector<int> res;
    for (int i = 0; i <= n; i++)
    {
      res.push_back(helperFunc(i, mem));
    }

    return res;
  }
};