#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
      int buy = i;
      for (int j = i + 1; j < prices.size(); j++)
      {
        int sell = j;
        int profit = prices[sell] - prices[buy];

        if (profit > maxProfit)
        {
          maxProfit = profit;
        }
      }
    }

    return maxProfit;
  }
};