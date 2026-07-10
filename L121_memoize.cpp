#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int helperFunc(vector<int> &prices, int transaction, int currIdx, vector<vector<int>> &mem)
  {
    if (currIdx == prices.size())
    {
      return 0;
    }
    if (transaction == 0)
    {
      return 0;
    }

    if (mem[transaction][currIdx] != -1)
    {
      return mem[transaction][currIdx];
    }

    if (transaction == 1)
    {
      // i can sell it or nothing...
      int a1 = helperFunc(prices, transaction - 1, currIdx + 1, mem) + prices[currIdx];
      int a2 = helperFunc(prices, transaction, currIdx + 1, mem);
      mem[transaction][currIdx] = max(a1, a2);
      return max(a1, a2);
    }
    else
    {
      int a1 = helperFunc(prices, transaction - 1, currIdx + 1, mem) - prices[currIdx];
      int a2 = helperFunc(prices, transaction, currIdx + 1, mem);
      mem[transaction][currIdx] = max(a1, a2);
      return max(a1, a2);
    }
  }

  int maxProfit(vector<int> &prices)
  {
    vector<vector<int>> mem(3, vector<int>(prices.size() + 1, -1));
    return helperFunc(prices, 2, 0, mem);
  }
};