#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int uniquePaths(int m, int n)
  {
    vector<vector<int>> mem(m, vector<int>(n, 1));
    for (int i = m - 2; i >= 0; i--)
    {
      for (int j = n - 2; j >= 0; j--)
      {
        mem[i][j] = mem[i + 1][j] + mem[i][j + 1];
      }
    }

    return mem[0][0];
  }
};