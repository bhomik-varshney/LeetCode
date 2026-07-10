#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int helperFunc(vector<int> &arr, int sumReq, int currIndex, vector<vector<int>> &mem1, vector<vector<int>> &mem2)
  {
    if (currIndex == arr.size())
    {
      // then check the sumReq...
      if (sumReq == 0)
      {
        return 1;
      }
      else
      {
        return 0;
      }
    }

    int val = arr[currIndex];

    if (sumReq < 0)
    {
      // it could be in mem2...
      if (mem2[currIndex][abs(sumReq)] != -1)
      {
        return mem2[currIndex][abs(sumReq)];
      }
      else
      {

        int a1 = helperFunc(arr, sumReq - val, currIndex + 1, mem1, mem2);
        int a2 = helperFunc(arr, sumReq + val, currIndex + 1, mem1, mem2);
        mem2[currIndex][abs(sumReq)] = a1 + a2;
        return a1 + a2;
      }
    }
    else
    {
      if (mem1[currIndex][sumReq] != -1)
      {
        return mem1[currIndex][sumReq];
      }
      else
      {
        int a1 = helperFunc(arr, sumReq - val, currIndex + 1, mem1, mem2);
        int a2 = helperFunc(arr, sumReq + val, currIndex + 1, mem1, mem2);
        mem1[currIndex][sumReq] = a1 + a2;
        return a1 + a2;
      }
    }
  }

  int sumOfArray(vector<int> &arr)
  {
    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      res += abs(arr[i]);
    }
    return res;
  }

  int totalWays(vector<int> &arr, int target)
  {
    int sum = sumOfArray(arr);
    vector<vector<int>> mem1(arr.size() + 1, vector<int>(abs(target) + sum + 1, -1));
    vector<vector<int>> mem2(arr.size() + 1, vector<int>(abs(target) + sum + 1, -1));
    //  code here
    // we can either add this to our target or decrease it to our target...
    // if we add it, target decreases, and if we subtract it, the target increases..
    return helperFunc(arr, target, 0, mem1, mem2);
  }
};