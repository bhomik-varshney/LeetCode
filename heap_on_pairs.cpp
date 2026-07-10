#include <iostream>
#include <queue>
#include <utility>

using namespace std;
struct cmp
{
  bool operator()(pair<int, string> &a, pair<int, string> &b)
  {
    // first :- min Heap , second :- max Heap

    if (a.first > b.first)
    {
      return true;
    }
    else if (a.first < b.first)
    {
      return false;
    }
    else
    {
      if (a.second < b.second)
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

class HeapOnPairs
{
public:
  void heapOnPairs()
  {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> heap;
  }
};

int main()
{
}