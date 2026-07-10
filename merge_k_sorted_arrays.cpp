#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp
{
  bool operator()(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
  {
    // make a min heap for first..
    if (a.first > b.first)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

class Solution
{
public:
  vector<int> mergeArrays(vector<vector<int>> &mat)
  {
    // Code here
    vector<int> res;

    int numOfArrays = mat.size();

    // heap will store as :- {value,arrayNumber,idx}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> heap;
    for (int i = 0; i < numOfArrays; i++)
    {
      pair<int, int> p = {i, 0};
      pair<int, pair<int, int>> p2 = {mat[i][0], p};
      heap.push(p2);
    }
    while (!heap.empty())
    {
      int val = heap.top().first;
      int arrayNum = heap.top().second.first;
      int idx = heap.top().second.second;
      heap.pop();
      res.push_back(val);
      idx++;
      if (idx < mat[arrayNum].size())
      {
        pair<int, int> p = {arrayNum, idx};
        pair<int, pair<int, int>> p2 = {mat[arrayNum][idx], p};
        heap.push(p2);
      }
      else
      {
        continue;
      }
    }

    return res;
  }
};

int main()
{
  Solution s1;
  vector<vector<int>> mat = {{1, 3, 5, 7}, {2, 4, 6, 8}, {0, 9, 10, 11}};
  vector<int> res = s1.mergeArrays(mat);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " , ";
  }
}