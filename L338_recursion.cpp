#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int helperFunc(int n)
  {
    if (n == 0)
    {
      return 0;
    }

    if (n % 2 == 0)
    {
      // even
      return helperFunc(n / 2);
    }
    else
    {
      // odd
      return helperFunc(n - 1) + 1;
    }
  }

  vector<int> countBits(int n)
  {
    vector<int> res;
    for (int i = 0; i <= n; i++)
    {
      res.push_back(helperFunc(i));
    }

    return res;
  }
};