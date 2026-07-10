#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int helperFunc(vector<int> &prices, int trans, int id, int idx, vector<vector<vector<int>>> &mem)
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
      if (mem[trans][id][idx] != -1)
      {
        return mem[trans][id][idx];
      }
      else
      {
        if (id == 1)
        {
          // only sell
          int a1 = helperFunc(prices, trans - 1, id + 1, idx + 1, mem) + prices[idx];
          int a2 = helperFunc(prices, trans, id, idx + 1, mem);
          mem[trans][id][idx] = max(a1, a2);
          return max(a1, a2);
        }
        else
        {
          // only buying
          int a1 = helperFunc(prices, trans, id - 1, idx + 1, mem) - prices[idx];
          int a2 = helperFunc(prices, trans, id, idx + 1, mem);
          mem[trans][id][idx] = max(a1, a2);
          return max(a1, a2);
        }
      }
    }
  }

  int maxProfit(int k, vector<int> &prices)
  {
    vector<vector<vector<int>>> mem(k + 1, vector<vector<int>>(3, vector<int>(prices.size() + 1, 0)));
    return helperFunc(prices, k, 2, 0, mem);
  }
};