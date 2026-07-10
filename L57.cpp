#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
  static bool comaparator(vector<int> &a, vector<int> &b)
  {
    return a[0] < b[0];
  }
  vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
  {
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end(), comaparator);
    vector<vector<int>> res;
    int start1 = intervals[0][0];
    int end1 = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++)
    {
      int start2 = intervals[i][0];
      int end2 = intervals[i][1];
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
    vector<int> new_range;
    new_range.push_back(start1);
    new_range.push_back(end1);
    res.push_back(new_range);
    return res;
  }
};

int main()
{
  vector<vector<int>> v = {{1, 3}, {6, 9}};
  vector<int> insert_interval = {2, 5};
  vector<vector<int>> result;
  solution s1;
  result = s1.insert(v, insert_interval);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i][0] << " , " << result[i][1] << endl;
  }
}