#include <iostream>
using namespace std;

class Solution
{
public:
  vector<int> Rearrange(vector<int> arr)
  {
    // using dutch national flag with one pass only...
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while (mid <= high)
    {
      if (arr[mid] == 1)
      {
        mid++;
      }
      else if (arr[mid] == 0)
      {
        int temp = arr[low];
        arr[low] = arr[mid];
        arr[mid] = temp;
        low++;
        mid++;
      }
      else
      {
        // swap with arr[high]...
        int temp = arr[high];
        arr[high] = arr[mid];
        arr[mid] = temp;
        high--;
      }
    }

    return arr;
  }

  vector<int> rearrange2(vector<int> arr)
  {
    int numOfZeroes = 0;
    int numOfOnes = 0;
    int numOfTwos = 0;

    for (auto i : arr)
    {
      if (i == 0)
      {
        numOfZeroes++;
      }
      else if (i == 1)
      {
        numOfOnes++;
      }
      else
      {
        numOfTwos++;
      }
    }

    int idx = 0;
    while (numOfZeroes != 0)
    {
      arr[idx] = 0;
      idx++;
      numOfZeroes--;
    }
    while (numOfOnes != 0)
    {
      arr[idx] = 1;
      idx++;
      numOfOnes--;
    }
    while (numOfTwos != 0)
    {
      arr[idx] = 2;
      idx++;
      numOfTwos--;
    }

    return arr;
  }
};

int main()
{
  Solution s1;
  vector<int> arr = {1, 0, 2};
  vector<int> res = s1.Rearrange(arr);
  for (auto i : res)
  {
    cout << i << " , ";
  }
}