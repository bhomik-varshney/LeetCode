#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

struct cmp
{
  bool operator()(const pair<int, int> &a, const pair<int, int> &b)
  {
    if (a.second > b.second)
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
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    vector<int> res;
    unordered_map<int, int> mp; // this is unordered map...
    for (int i = 0; i < nums.size(); i++)
    {
      mp[nums[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> heap;
    // it will make min heap based on the value of pair.second

    for (const auto &[val, freq] : mp)
    {
      pair<int, int> p1 = {val, freq};
      if (heap.size() < k)
      {
        heap.push(p1);
      }
      else
      {
        if (heap.top().second < freq)
        {
          heap.pop();
          heap.push(p1);
        }
      }
    }

    while (!heap.empty())
    {
      res.push_back(heap.top().first);
      heap.pop();
    }
    return res;
  }
};

int main()
{
  vector<int> v1 = {1, 1, 1, 2, 2, 3};
  int k = 2;
  Solution s1;
  vector<int> res = s1.topKFrequent(v1, k);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " , ";
  }
}