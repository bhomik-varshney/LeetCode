#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int helperFunc(vector<int> &prices, int trans, int id, int idx)
  {
    if (idx == prices.size())
    {
      return 0;
    }

    if (trans == 0)
    {
      return 0;
    }
    else
    {
      if (id == 1)
      {
        // only sell
        int a1 = helperFunc(prices, trans - 1, id + 1, idx + 1) + prices[idx];
        int a2 = helperFunc(prices, trans, id, idx + 1);
        return max(a1, a2);
      }
      else
      {
        // only buying
        int a1 = helperFunc(prices, trans, id - 1, idx + 1) - prices[idx];
        int a2 = helperFunc(prices, trans, id, idx + 1);
        return max(a1, a2);
      }
    }
  }

  int maxProfit(int k, vector<int> &prices)
  {
    return helperFunc(prices, k, 2, 0);
  }
};