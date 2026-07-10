#include <iostream>
using namespace std;

class Solution
{
public:
  int helperFunc(int m, int n, int i, int j)
  {
    if (i == m - 1 && j == n - 1)
    {
      return 1;
    }

    // if went down... means i, j to i+1, j
    int a1 = 0;
    int a2 = 0;

    if (i + 1 < m)
    {
      a1 = helperFunc(m, n, i + 1, j);
    }

    if (j + 1 < n)
    {
      a2 = helperFunc(m, n, i, j + 1);
    }

    return a1 + a2;
  }

  int uniquePaths(int m, int n)
  {
    return helperFunc(m, n, 0, 0);
  }
};