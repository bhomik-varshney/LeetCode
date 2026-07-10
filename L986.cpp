#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
  {
    vector<vector<int>> res;
    if (firstList.size() != 0 && secondList.size() != 0)
    {
      int i = 0;
      int j = 0;
      int start1 = firstList[i][0];
      int end1 = firstList[i][1];

      int start2 = secondList[j][0];
      int end2 = secondList[j][1];

      while (i < firstList.size() && j < secondList.size())
      {
        vector<int> intersection;
        intersection.push_back(max(start1, start2));
        intersection.push_back(min(end1, end2));

        if (max(start1, start2) <= min(end1, end2))
        {
          res.push_back(intersection);
          // cout << max(start1, start2) << " , " << min(end1, end2) << endl;
        }

        if (end1 > end2)
        {
          j++;
          if (j < secondList.size())
          {
            start2 = secondList[j][0];
            end2 = secondList[j][1];
          }
        }
        else if (end1 < end2)
        {
          i++;
          if (i < firstList.size())
          {
            start1 = firstList[i][0];
            end1 = firstList[i][1];
          }
        }

        else
        {
          i++;
          j++;
          if (i < firstList.size() && j < secondList.size())
          {
            start1 = firstList[i][0];
            end1 = firstList[i][1];

            start2 = secondList[j][0];
            end2 = secondList[j][1];
          }
        }
      }
    }
    return res;
  }
};

int main()
{
  Solution s1;
  vector<vector<int>> firstList = {{1, 3}, {5, 9}};
  vector<vector<int>> secondList = {};
  vector<vector<int>> result = s1.intervalIntersection(firstList, secondList);
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i][0] << " , " << result[i][1] << endl;
  }
}