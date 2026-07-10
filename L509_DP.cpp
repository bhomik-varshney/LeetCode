#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int helperFunc(int n, vector<int> &memory)
  {
    if (memory[n] != -1)
    {
      return memory[n];
    }

    int a1 = helperFunc(n - 1, memory);
    memory[n - 1] = a1;
    int a2 = helperFunc(n - 2, memory);
    memory[n - 2] = a2;

    memory[n] = a1 + a2;
    return a1 + a2;
  }

  int fib(int n)
  {
    vector<int> memory(n + 2, -1);
    memory[0] = 0;
    memory[1] = 1;

    int res = helperFunc(n, memory);
    return res;
  }
};