#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

struct cmp
{
  bool operator()(pair<int, int> &a, pair<int, int> &b)
  {
    // first :- max heap, second :- min heap
    if (a.first > b.first)
    {
      return false;
    }
    else if (a.first < b.first)
    {
      return true;
    }
    else
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
  }
};

class Solution
{
public:
  int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
  {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> heap;
    stack<pair<int, int>> st;
    // fill in the heap..
    for (int i = 0; i < profits.size(); i++)
    {
      pair<int, int> p = {profits[i], capital[i]};
      heap.push(p);
    }
    while (k != 0 && !heap.empty())
    {
      int profit = heap.top().first;
      int weight = heap.top().second;

      while (weight > w && !heap.empty())
      {
        pair<int, int> p1 = {profit, weight};
        heap.pop();
        st.push(p1);
        weight = heap.top().second;
        profit = heap.top().first;
      }
      if (weight <= w && !heap.empty())
      {
        w += heap.top().first;
        k--;
        heap.pop();
        // this entry would not be used...
      }
      else if (heap.empty())
      {
        break;
      }
      while (!st.empty())
      { // restore back all the unecessary pop values...
        int x = st.top().first;
        int y = st.top().second;
        pair<int, int> p2 = {x, y};
        heap.push(p2);
        st.pop();
      }
    }

    return w;
  }
};

int main()
{
  Solution s1;
  vector<int> profits = {1, 2, 3};
  vector<int> capital = {1, 1, 2};
  cout << s1.findMaximizedCapital(1, 2, profits, capital);
}