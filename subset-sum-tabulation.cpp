#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool isSubsetSum(vector<int> &arr, int sum)
  {
    // code here

    vector<vector<bool>> mem(sum + 1, vector<bool>(arr.size() + 1, false));

    for (int i = 0; i < arr.size(); i++) // base case filling
    {
      mem[sum][i] = true;
    }

    // now start filling all the cells...
    for (int j = arr.size() - 1; j >= 0; j--)
    {
      int currIndex = j;
      for (int i = sum - 1; i >= 0; i--)
      {
        int currSum = i;

        // find its findings...
        int newSum = currSum + arr[currIndex];
        bool a1;
        bool a2;
        if (newSum > sum)
        {
          // we have make it false already....
          a1 = false;
          a2 = mem[currSum][currIndex + 1];
        }
        else
        {
          // means we can search both aspects...
          a1 = mem[newSum][currIndex + 1];
          a2 = mem[currSum][currIndex + 1];
        }
        mem[currSum][currIndex] = a1 || a2;
      }
    }
    return mem[0][0]; // as currSum = 0 , currIndex = 0;
  }
};