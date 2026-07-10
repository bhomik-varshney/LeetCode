#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        vector<vector<int>> mem(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = text1.size() - 1; i >= 0; i--)
        {
            for (int j = text2.size() - 1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                {
                    mem[i][j] = 1 + mem[i + 1][j + 1];
                }
                else
                {
                    mem[i][j] = max(mem[i + 1][j], mem[i][j + 1]);
                }
            }
        }

        return mem[0][0];
    }
};