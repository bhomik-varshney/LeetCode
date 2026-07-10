#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int knapsack(int W, vector<int> &val, vector<int> &wt)
  {
    // code here
    vector<vector<int>> mem(val.size() + 1, vector<int>(W + 1, 0));

    // now find
    for (int j = W - 1; j >= 0; j--)
    {
      int currWeight = j;
      for (int i = val.size() - 1; i >= 0; i--)
      {
        int currIndex = i;
        if (currWeight + wt[currIndex] <= W)
        {
          mem[currIndex][currWeight] = max(mem[currIndex + 1][currWeight + wt[currIndex]] + val[currIndex], mem[currIndex + 1][currWeight]);
        }
        else
        {
          mem[currIndex][currWeight] = mem[currIndex + 1][currWeight];
        }
      }
    }
    return mem[0][0];
  }
};