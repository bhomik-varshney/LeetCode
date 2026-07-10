#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    vector<vector<int>> mem(3, vector<int>(prices.size() + 1, 0));
    for (int j = prices.size() - 1; j >= 0; j--)
    {
      for (int i = 1; i < 3; i++)
      {
        if (i == 2)
        {
          mem[i][j] = max(mem[i - 1][j + 1] - prices[j], mem[i][j + 1]);
        }
        else
        {
          mem[i][j] = max(mem[i + 1][j + 1] + prices[j], mem[i][j + 1]);
        }
      }
    }
    return mem[2][0];
  }
};