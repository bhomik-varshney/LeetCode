#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

struct cmp
{
  bool operator()(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)
  {
    // min heap...
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
  int kthSmallest(vector<vector<int>> &matrix, int k)
  {
    // we will think of k sorted arrays, and maintain a min heap to find the size of k and then pop it to find the kth smallest...
    int res;
    int numOfArrays = matrix.size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> heap;
    for (int i = 0; i < numOfArrays; i++)
    {
      pair<int, int> p = {i, 0};
      pair<int, pair<int, int>> p2 = {matrix[i][0], p};
      heap.push(p2);
    }
    int popTimes = 0;
    // i have to find the kth smallest element, it means that kth element will have k-1 smallest element before it....
    popTimes = 0;
    while (popTimes != k - 1)
    {
      int val = heap.top().first;
      int arrayNum = heap.top().second.first;
      int idx = heap.top().second.second;

      heap.pop();
      popTimes++;

      idx++;
      if (idx < matrix[arrayNum].size())
      {
        pair<int, int> p = {arrayNum, idx};
        pair<int, pair<int, int>> p2 = {matrix[arrayNum][idx], p};
        heap.push(p2);
      }
    }
    return heap.top().first;
  }
};

int main()
{
  Solution s1;
  vector<vector<int>> matrix = {{1, 2}, {1, 3}};
  cout << s1.kthSmallest(matrix, 4);
}