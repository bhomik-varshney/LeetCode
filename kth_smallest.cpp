#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
  void findMax(vector<int> &arr, int &min, int &max)
  {
    int MAX = INT_MIN;
    int MIN = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] > MAX)
      {
        MAX = arr[i];
      }
      if (arr[i] < MIN)
      {
        MIN = arr[i];
      }
    }
    min = MIN;
    max = MAX;
  }

  int numBefore(vector<int> &arr, int val)
  {
    int num = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] <= val)
      {
        num++;
      }
    }
    return num;
  }

  bool exist(vector<int> &arr, int val)
  {
    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i] == val)
      {
        return true;
      }
    }
    return false;
  }

  int kthSmallest3(vector<int> &arr, int k)
  {
    // code here
    int res = -1;

    int min;
    int max;
    findMax(arr, min, max);

    while (min <= max)
    {
      int mid = (min + max) / 2;
      if (numBefore(arr, mid) >= k)
      {
        if (exist(arr, mid))
        {
          res = mid;
        }
        max = mid - 1;
      }
      else
      {
        min = mid + 1;
      }
    }
    // O(Rlogn); R is the range max - min, and n is the number of array elements...

    return res;
  }

  int kthSmallest2(vector<int> &arr, int k)
  {
    // now we can use the max heap but in a negative number order...
    priority_queue<int> heap;
    // insertion
    for (int i = 0; i < arr.size(); i++)
    {
      heap.push(-1 * arr[i]); // takes O(nlogn)
    }

    // to find the kth smallest element...
    for (int i = 0; i < k - 1; i++) // takes O(klogn)
    {
      heap.pop();
    }
    // O(nlogn); n is the number of elements of an array...
    return -1 * heap.top();
  }

  int kthSmallest(vector<int> &arr, int k)
  {
    priority_queue<int> heap;
    for (int i = 0; i < arr.size(); i++)
    {
      if (heap.size() < k)
      {
        heap.push(arr[i]); // use max heap to find the kth smallest element...
      }
      else
      {
        if (heap.top() > arr[i])
        {
          heap.pop();
          heap.push(arr[i]);
        }
        else
        {
          continue;
        }
      }
    }
    // O(nlogk); where k is the kth smallest valye given and n is the number of elements of an array...
    return heap.top();
  }
};

int main()
{
  Solution s1;
  vector<int> arr = {10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
  int k = 4;
  cout << s1.kthSmallest3(arr, k) << endl;
  cout << s1.kthSmallest2(arr, k) << endl;
  cout << s1.kthSmallest(arr, k) << endl;
}