#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int maximumSum(vector<int> &arr)
  {
    int nodelete = arr[0];
    int onedelete = arr[0];
    int ans = nodelete;
    for (int i = 1; i < arr.size(); i++)
    {
      // if we are deleting a[i]. or we have deleted any one option from the subarray before...
      onedelete = max(nodelete, onedelete + arr[i]);

      // we are not deleting any element
      nodelete = max(nodelete + arr[i], arr[i]);
      ans = max(ans, max(onedelete, nodelete));
    }

    return ans;
  }
};

int main()
{
  Solution s1;
  vector<int> v = {2, 1, -2, -5, -2};
  cout << s1.maximumSum(v);
}
