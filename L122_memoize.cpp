#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int helperFunc(vector<int> &prices, int trans, int idx, vector<vector<int>> &mem)
  {
    if (idx == prices.size())
    {
      return 0; // no trans could be done..
    }

    if (mem[trans][idx] != -1)
    {
      return mem[trans][idx];
    }
    else
    {
      if (trans == 2)
      {
        // you can buy/ not buy stock...
        int a1 = helperFunc(prices, trans - 1, idx + 1, mem) - prices[idx];
        int a2 = helperFunc(prices, trans, idx + 1, mem);
        mem[trans][idx] = max(a1, a2);
        return max(a1, a2);
      }
      else
      {
        // we can sell it/ not sell it
        int a1 = helperFunc(prices, trans + 1, idx + 1, mem) + prices[idx];
        int a2 = helperFunc(prices, trans, idx + 1, mem);
        mem[trans][idx] = max(a1, a2);
        return max(a1, a2);
      }
    }
  }

  int maxProfit(vector<int> &prices)
  {
    vector<vector<int>> mem(3, vector<int>(prices.size() + 1, -1));
    return helperFunc(prices, 2, 0, mem);
  }
};