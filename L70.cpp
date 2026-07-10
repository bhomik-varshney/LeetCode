#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int,int> mem;
    int climbStairs(int n) 
    {
        if(n == 1)
        {
            return 1;
        }
        if(n == 2)
        {
            return 2;
        }

        if(mem.find(n) != mem.end())
        {
            return mem[n];
        }
        else
        {
            int a1 = climbStairs(n-1);
            int a2 = climbStairs(n-2);
            mem[n] = a1+a2;
            return a1+a2;
        }  
    }
};