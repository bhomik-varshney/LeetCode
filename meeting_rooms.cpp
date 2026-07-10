#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int minMeetingRooms(vector<int> &start, vector<int> &end)
  {
    // code here
    int max_rooms = 0;
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    int i = 0;
    int j = 0;
    int rooms = 0;
    while (i < start.size())
    {
      if (start[i] < end[j])
      {
        rooms++;
        i++;
      }
      else if (end[j] <= start[i]) // agar dono room start bhi 10 pr ho rha hai and end bhi 10 pr ho rha hai, toh pehle khaali karwa lo , phir start karna
      {
        // room khali krna hai
        rooms--;
        j++;
      }

      max_rooms = max(max_rooms, rooms);
    }

    return max_rooms;
  }
};

// my old logic

// class Solution
// {
// public:
//   static bool comparator(vector<int> &a, vector<int> &b)
//   {
//     return a[0] < b[0];
//   }

//   int minEnd(vector<int> ends)
//   {
//     int minIndex = -1;
//     int minValue = INT_MAX;
//     for (int i = 0; i < ends.size(); i++)
//     {
//       if (ends[i] != 0 && ends[i] < minValue)
//       {
//         minIndex = i;
//         minValue = ends[i];
//       }
//     }
//     return minIndex;
//   }

//   int minMeetingRooms(vector<int> &start, vector<int> &end)
//   {
//     // code here
//     int res = 0;
//     if (start.size() != 0)
//     {

//       vector<vector<int>> intervals;
//       for (int i = 0; i < start.size(); i++)
//       {
//         vector<int> new_interval;
//         new_interval.push_back(start[i]);
//         new_interval.push_back(end[i]);
//         intervals.push_back(new_interval);
//       }

//       sort(intervals.begin(), intervals.end(), comparator);

//       vector<int> ends(end.size());
//       int start1 = intervals[0][0];
//       int end1 = intervals[0][1];
//       res++;
//       ends.push_back(end1);
//       for (int i = 1; i < intervals.size(); i++)
//       {
//         int start2 = intervals[i][0];
//         int end2 = intervals[i][1];
//         if (start2 < ends[minEnd(ends)])
//         {

//           res++;
//         }
//         else
//         {
//           int index = minEnd(ends);
//           ends[index] = INT_MAX;
//         }
//         ends.push_back(end2);
//       }
//     }

//     return res;
//   }
// };

int main()
{

  vector<int> start = {1, 10, 7};
  vector<int> end = {4, 15, 10};
  Solution s1;
  cout << s1.minMeetingRooms(start, end);
}