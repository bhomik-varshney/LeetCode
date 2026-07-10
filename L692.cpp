#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

struct cmp
{
  bool operator()(pair<string, int> &a, pair<string, int> &b)
  {
    // we are making min heap...
    if (a.second > b.second)
    {
      return true;
    }
    else if (a.second < b.second)
    {
      return false;
    }
    else
    {
      if (a.first > b.first)
      {
        return false;
      }
      else
      {
        return true;
      }
    }
  }
};

class Solution
{
public:
  vector<string> topKFrequent(vector<string> &words, int k)
  {
    vector<string> res;
    // use hashmap
    unordered_map<string, int> map;
    for (int i = 0; i < words.size(); i++)
    {
      map[words[i]]++;
    }
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> heap;
    for (auto i : map)
    {
      pair<string, int> p = {i.first, i.second};
      if (heap.size() < k)
      {
        heap.push(p);
      }
      else
      {
        if (heap.top().second < i.second)
        {
          heap.pop();
          heap.push(p);
        }
        else if (heap.top().second > i.second)
        {
          continue;
        }
        else
        {
          if (heap.top().first > i.first)
          {
            heap.pop();
            heap.push(p);
          }
        }
      }
    }
    stack<string> st;
    // push into the res...
    while (!heap.empty())
    {
      string p;
      p = heap.top().first;
      st.push(p);
      heap.pop();
    }

    while (!st.empty())
    {
      res.push_back(st.top());
      st.pop();
    }

    return res;
  }
};