#include <iostream>
using namespace std;

class Solution
{
public:
  int countSet(int n)
  {
    // use kurning han..
    int count = 0;
    while (n != 0)
    {
      n = n & (n - 1);
      count++;
    }

    return count;
  }

  vector<int> countBits(int n)
  {
    vector<int> res;

    // taking number from 0 to n....
    for (int i = 0; i <= n; i++)
    {
      int count = countSet(i);
      res.push_back(count);
    }

    return res;
  }
};