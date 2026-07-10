#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// User function Template for C++
class Solution
{
public:
  void subsets(vector<int> &arr, int n, int idx, vector<int> &temp, vector<vector<int>> &res)
  {
    if (idx == n) // base case
    {
      cout << "printing answer in temp into result" << endl;
      // we have no choice , simply print the result
      res.push_back(temp);
      return;
    }

    // if index = idx element is not taken...
    subsets(arr, n, idx + 1, temp, res);
    cout << "element " << arr[idx] << " is not taken into account" << endl;
    // if index = idx element is taken...
    temp.push_back(arr[idx]);
    cout << arr[idx] << " is pushed into the temp (taken in account)" << endl;
    subsets(arr, n, idx + 1, temp, res);
    temp.pop_back(); // reversing my decision...(backtracking)
    cout << temp[temp.size() - 1] << " is removed " << endl;
  }
};

int main()
{
  Solution s1;
  vector<int> arr = {1, 2, 3};
  vector<vector<int>> v;
  vector<int> temp;
  s1.subsets(arr, arr.size(), 0, temp, v);
  for (int i = 0; i < v.size(); i++)
  {
    cout << " { ";
    for (int j = 0; j < v[i].size(); j++)
    {
      cout << v[i][j] << ", ";
    }
    cout << " }" << endl;
  }
}