#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    vector<vector<int>> mem(3, vector<int>(prices.size() + 1, 0));
    // tabulation...
    for (int i = 1; i < 3; i++)
    {
      for (int j = prices.size() - 1; j >= 0; j--)
      {
        int trans = i;
        int currIdx = j;
        if (trans == 1)
        {
          mem[trans][currIdx] = max(mem[trans - 1][currIdx + 1] + prices[currIdx], mem[trans][currIdx + 1]);
        }
        else
        {
          // it will only 2
          mem[trans][currIdx] = max(mem[trans - 1][currIdx + 1] - prices[currIdx], mem[trans][currIdx + 1]);
        }
      }
    }

    return mem[2][0];
  }
};