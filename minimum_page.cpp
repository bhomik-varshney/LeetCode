#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int sumOfArray(vector<int> &arr)
  {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      sum += arr[i];
    }
    return sum;
  }

  bool check(vector<int> arr, int k, int val)
  {
    // we have given the number of maximum pages that could be there to that configuration...

    int students = 1;
    int pages = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      if ((pages + arr[i]) <= val)
      {
        pages += arr[i];
      }
      else
      {
        students++;
        pages = arr[i];
        if (students > k)
        {
          return false;
          break;
        }
      }
    }

    return true;
  }

  int findMax(vector<int> &arr)
  {
    int maxVal = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] > maxVal)
      {
        maxVal = arr[i];
      }
    }

    return maxVal;
  }

  int findPages(vector<int> &arr, int k)
  {
    int res = INT_MAX;
    int low = findMax(arr);
    int high = sumOfArray(arr);
    if (k <= arr.size())
    {
      while (low <= high)
      {
        int mid = (low + high) / 2;
        if (check(arr, k, mid))
        {
          if (res > mid)
          {
            res = mid;
          }
          high = mid - 1;
        }
        else
        {
          low = mid + 1;
        }
      }
      return res;
    }
    else
    {
      return -1;
    }
  }
};

int main()
{
  Solution s1;
  vector<int> books = {12, 34, 67, 90};
  cout << s1.findPages(books, 2) << endl;
}