#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct cmp
{
  bool operator()(pair<char, int> &a, pair<char, int> &b)
  {
    // max heap...
    if (a.second > b.second)
    {
      return false;
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
  void decreaseLife(unordered_map<char, pair<pair<int, int>, bool>> &map)
  {
    for (auto &i : map)
    {
      i.second.first.second--;
    }
  }
  int leastInterval(vector<char> &tasks, int n)
  {
    int count = 0;
    // val -> freq,life,inside
    unordered_map<char, pair<pair<int, int>, bool>> map;
    priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> heap;
    for (int i = 0; i < tasks.size(); i++)
    {
      map[tasks[i]].first.first++;
      map[tasks[i]].first.second = 0;
    }
    while (!map.empty())
    {
      for (auto &i : map)
      {
        char val = i.first;
        int freq = i.second.first.first;
        int life = i.second.first.second;
        if (i.second.second == false && life <= 0)
        {
          // just push it into the heap...
          pair<char, int> p = {val, freq};
          i.second.second = true;
          heap.push(p);
        }
      }

      if (!heap.empty())
      {
        // add into the heap...
        char val = heap.top().first;
        int freq = heap.top().second;
        map[val].first.first--;
        freq--;
        heap.pop();
        count++;
        decreaseLife(map);
        map[val].second = false;
        map[val].first.second = n;
        if (freq == 0)
        {
          map.erase(val);
        }
      }
      else
      {
        // no one is in the heap...
        count++;
        decreaseLife(map);
      }
    }

    return count;
  }
};

int main()
{
  Solution s1;
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  int n = 2;
  cout << s1.leastInterval(tasks, n);
}