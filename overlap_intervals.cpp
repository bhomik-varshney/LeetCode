#include <iostream>
using namespace std;

class Solution
{
public:
  static bool comparator(vector<int> &a, vector<int> &b)
  {
    return a[0] < b[0];
  }
  bool isIntersect(vector<vector<int>> intervals)
  {
    // Code Here
    sort(intervals.begin(), intervals.end(), comparator);
    int i = 1;
    int start1 = intervals[0][0];
    int end1 = intervals[0][1];
    while (i < intervals.size())
    {
      int start2 = intervals[i][0];
      int end2 = intervals[i][1];

      if (end1 >= start2)
      {
        return true;

        break;
      }
      start1 = intervals[i][0];
      end1 = intervals[i][1];
      i++;
    }
    return false;
  }
};

int main()
{

  Solution s1;
  vector<vector<int>> firstList = {{1, 3}, {7, 9}, {4, 6}, {10, 13}};
  cout << s1.isIntersect(firstList);
}