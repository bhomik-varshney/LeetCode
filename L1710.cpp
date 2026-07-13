#include <iostream>
#include <vector>
using namespace std;

struct cmp
{
  bool operator()(pair<int, int> &a, pair<int, int> &b)
  {
    if (a.first > b.first)
    {
      return false; // max heap
    }
    else
    {
      return true;
    }
  }
};

class Solution
{
public:
  int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
  {
    int ans = 0;
    // in this the boxes must be minimum , and the units must be maximum...
    // hence the greedy value is the units/boxes..
    int currSize = truckSize;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> heap; // greedyValue , index in boxTypes

    // calc the g value and put into the heap..
    for (int i = 0; i < boxTypes.size(); i++)
    {
      int gValue = boxTypes[i][1];
      int idx = i;
      heap.push({gValue, idx});
    }

    while (!heap.empty())
    {
      int idx = heap.top().second;
      heap.pop();
      if (currSize == 0)
      {
        continue;
      }
      else
      {
        if (boxTypes[idx][0] <= currSize)
        {
          ans += (boxTypes[idx][0] * boxTypes[idx][1]); // added all the units..
          currSize -= boxTypes[idx][0];
        }
        else
        {
          // we need to make the currSize boxes to be added...
          ans += currSize * boxTypes[idx][1];
          currSize = 0;
        }
      }
    }

    return ans;
  }
};