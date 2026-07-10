#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

struct cmp
{
  bool operator()(pair<char, int> &a, pair<char, int> &b)
  {
    // max heap
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
  int leastInterval(vector<char> &tasks, int n)
  {
    unordered_map<char, pair<int, pair<int, bool>>> map; // char, freq, free,inside
    for (int i = 0; i < tasks.size(); i++)
    {
      map[tasks[i]].first++;
      map[tasks[i]].second.first = 0;      // all can come at 0th seat
      map[tasks[i]].second.second = false; // not inside heap
    }
    int seatNumber = 0;
    // go upto tasks.size()
    int count = 0;
    priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> heap;
    while (!map.empty())
    {
      for (auto &i : map)
      {
        if (i.second.second.first <= seatNumber && i.second.second.second == false)
        {
          pair<char, int> p = {i.first, i.second.first};
          heap.push(p);
          i.second.second.second = true; // now its inside...
        }
      }
      if (!heap.empty())
      {
        char val = heap.top().first;
        int freq = heap.top().second;
        count++;
        seatNumber++;
        map[val].first--;
        freq--;
        heap.pop();
        map[val].second.second = false;
        map[val].second.first += n + 1;
        if (freq == 0)
        {
          // remove entry..
          map.erase(val);
        }
      }
      else
      {
        count++; // idle situation...
        seatNumber++;
      }
    }
    return count;
  }
};

int main()
{
}