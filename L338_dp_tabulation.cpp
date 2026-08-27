#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> countBits(int n)
  {
    vector<int> mem(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
      if (i % 2 == 0)
      {
        // even
        mem[i] = mem[i / 2];
      }
      else
      {
        // odd
        mem[i] = mem[i - 1] + 1;
      }
    }

    return mem;
  }
};