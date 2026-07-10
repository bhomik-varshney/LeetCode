#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
  {
    // bellmand ford relaxes all th edges one by one...
    vector<int> dis(n, INT_MAX);
    dis[src] = 0;
    vector<int> temp = dis;
    for (int i = 0; i < k + 1; i++)
    {
      // relax every edge...
      for (int j = 0; j < flights.size(); j++)
      {
        int s = flights[j][0];
        int d = flights[j][1];
        int price = flights[j][2];

        if (dis[s] != INT_MAX && temp[d] > dis[s] + price)
        {
          temp[d] = dis[s] + price;
        }
      }

      // change the dis into temp...
      dis = temp;
    }

    if (dis[dst] == INT_MAX)
    {
      return -1;
    }
    else
    {
      return dis[dst];
    }
  }
};