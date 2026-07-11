#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int helperFunc(vector<int> &cuts, int i, int j, vector<vector<int>> &mem)
  {
    int res = INT_MAX;
    if (i > j)
    {
      return 0;
    }

    if (mem[i][j] != -1)
    {
      return mem[i][j];
    }

    // now do the same for each one of them to cut...
    for (int k = i; k <= j; k++)
    {
      int cost = cuts[j + 1] - cuts[i - 1];
      int a1 = helperFunc(cuts, i, k - 1, mem) + helperFunc(cuts, k + 1, j, mem) + cost;
      res = min(res, a1);
    }
    mem[i][j] = res;
    return res;
  }

  int minCost(int n, vector<int> &cuts)
  {
    // change the cuts...
    vector<int> newCuts;
    newCuts.push_back(0);
    for (int i = 0; i < cuts.size(); i++)
    {
      newCuts.push_back(cuts[i]);
    }
    newCuts.push_back(n);
    sort(newCuts.begin(), newCuts.end());
    vector<vector<int>> mem(cuts.size() + 1, vector<int>(cuts.size() + 1, -1));
    return helperFunc(newCuts, 1, cuts.size(), mem);
  }
};