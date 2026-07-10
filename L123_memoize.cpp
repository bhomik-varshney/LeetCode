#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int helperFunc(vector<int> &prices, int trans, int id, int currIdx, vector<vector<vector<int>>> &mem)
  {

    if (currIdx == prices.size())
    {
      return 0;
    }

    if (trans == 0)
    {
      return 0;
    }
    else
    {
      if (mem[trans][id][currIdx] != -1)
      {
        return mem[trans][id][currIdx];
      }
      else
      {
        if (id == 1)
        {
          // i can only sell it...
          int a1 = helperFunc(prices, trans - 1, id + 1, currIdx + 1, mem) + prices[currIdx];
          int a2 = helperFunc(prices, trans, id, currIdx + 1, mem);
          mem[trans][id][currIdx] = max(a1, a2);
          return max(a1, a2);
        }
        else
        {
          // i can buy or not buy..
          int a1 = helperFunc(prices, trans, id - 1, currIdx + 1, mem) - prices[currIdx];
          int a2 = helperFunc(prices, trans, id, currIdx + 1, mem);
          mem[trans][id][currIdx] = max(a1, a2);
          return max(a1, a2);
        }
      }
    }
  }

  int maxProfit(vector<int> &prices)
  {
    vector<vector<vector<int>>> mem(3, vector<vector<int>>(3, vector<int>(prices.size() + 1, -1))); // trans -> id -> idx
    return helperFunc(prices, 2, 2, 0, mem);
  }
};