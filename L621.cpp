#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

struct cmp
{
  bool operator()(pair<int, pair<char, int>> &a, pair<int, pair<char, int>> &b)
  {
    // max heap...
    if (a.first > b.first)
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
  void decreaseLife(unordered_map<char, int> &map)
  {
    for (auto &i : map)
    {
      i.second--;
    }
  }

  int leastInterval(vector<char> &tasks, int n)
  {
    int count = 0;
    // max heap will store, the value of freq , val, n
    priority_queue<pair<int, pair<char, int>>, vector<pair<int, pair<char, int>>>, cmp> heap;
    unordered_map<char, int> map;
    for (int i = 0; i < tasks.size(); i++)
    {
      map[tasks[i]]++;
    }

    for (auto &i : map)
    {
      char val = i.first;
      int freq = i.second;
      int life = 0;
      pair<char, int> p1 = {val, life};
      pair<int, pair<char, int>> p2 = {freq, p1};
      heap.push(p2);
      // now map will help to store the life of that particular character instead of frequency...
      i.second = life;
    }

    stack<pair<int, pair<char, int>>> st;

    while (!heap.empty())
    {
      int freq = heap.top().first;
      char val = heap.top().second.first;
      int life = heap.top().second.second;
      if (map[val] <= 0)
      {
        // means we can use that particular character...
        count++;
        decreaseLife(map);
        freq--;
        if (freq == 0)
        {
          heap.pop();
        }
        else
        {
          heap.pop();
          map[val] = n;
          pair<char, int> p1 = {val, life};
          pair<int, pair<char, int>> p2 = {freq, p1};
          heap.push(p2);
        }
      }
      else
      {
        // we can not make that value, we have to pop that value to get the new values...
        while (!heap.empty() && map[heap.top().second.first] > 0)
        {
          st.push(heap.top());
          heap.pop();
        }

        if (heap.empty())
        {
          // idle situation
          count++;
          decreaseLife(map);
        }
        else
        {
          int freq = heap.top().first;
          char val = heap.top().second.first;
          int life = heap.top().second.second;
          freq--;
          count++;
          // as the count value increases , the value for all life or n must decrease by 1...
          decreaseLife(map);
          if (freq == 0)
          {
            heap.pop();
          }
          else
          {
            heap.pop();
            map[val] = n;
            pair<char, int> p1 = {val, life};
            pair<int, pair<char, int>> p2 = {freq, p1};
            heap.push(p2);
          }
        }

        while (!st.empty())
        {
          heap.push(st.top());
          st.pop();
        }
      }
    }
    return count;
  }
};

int main()
{
  Solution s1;
  vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
  int n = 3;
  cout << s1.leastInterval(tasks, n);
}