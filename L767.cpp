#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct cmp
{
  bool operator()(pair<char, int> &a, pair<char, int> &b)
  {
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
  string reorganizeString(string s)
  {
    string res;
    unordered_map<char, int> map;
    for (int i = 0; i < s.size(); i++)
    {
      map[s[i]]++;
    }
    cout << map.size() << endl;
    priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> heap;
    for (auto i : map)
    {
      pair<char, int> p = {i.first, i.second};
      heap.push(p);
    }

    // now remove all of them and make a reorganized string...
    int idx = 0;
    while (!heap.empty())
    {
      char val = heap.top().first;
      int freq = heap.top().second;
      if (idx == 0)
      {
        res.push_back(val);
        idx++;
        freq--;
        pair<char, int> p = {val, freq};
        if (freq != 0)
        {
          heap.pop();
          heap.push(p);
        }
        else
        {
          heap.pop();
        }
      }
      else
      {
        if (res[idx - 1] != val)
        {
          idx++;
          freq--;
          res.push_back(val);
          pair<char, int> p = {val, freq};
          if (freq != 0)
          {
            heap.pop();
            heap.push(p);
          }
          else
          {
            heap.pop();
          }
        }
        else
        {
          heap.pop();
          if (!heap.empty())
          {
            char val2 = heap.top().first;
            int freq2 = heap.top().second;
            idx++;
            freq2--;
            res.push_back(val2);
            pair<char, int> p1 = {val2, freq2};
            pair<char, int> p = {val, freq};
            if (freq2 != 0)
            {
              heap.pop();
              heap.push(p1);
            }
            else
            {
              heap.pop();
            }
            heap.push(p);
          }
          else
          {
            res = "";
            break;
          }
        }
      }
    }

    return res;
  }
};

int main()
{
  Solution s1;
  string res = s1.reorganizeString("aab");
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i];
  }
}