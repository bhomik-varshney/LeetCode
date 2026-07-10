#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  static bool comparator(vector<int> &a, vector<int> &b)
  {
    return a[0] < b[0];
  }
  vector<vector<int>> merge(vector<vector<int>> &arr)
  {

    sort(arr.begin(), arr.end(), comparator); // we are sorting the function by first or starting value of each range value. such as :- start1, start2, start3, start4, etc...
    vector<vector<int>> res;
    int start1 = arr[0][0];
    int end1 = arr[0][1];
    for (int i = 1; i < arr.size(); i++)
    {
      int start2 = arr[i][0];
      int end2 = arr[i][1];

      if (end1 >= start2)
      {
        start1 = start1;
        end1 = max(end1, end2);
      }
      else
      {
        vector<int> new_range;
        new_range.push_back(start1);
        new_range.push_back(end1);
        res.push_back(new_range);
        start1 = start2;
        end1 = end2;
      }
    }
    vector<int> new_range = {start1, end1};
    res.push_back(new_range);
    return res;
  }
};

int main()
{
  Solution s1;
  vector<vector<int>> v = {{4, 7}, {1, 4}};
  vector<vector<int>> result = s1.merge(v);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i][0] << " , " << result[i][1] << endl;
  }
}