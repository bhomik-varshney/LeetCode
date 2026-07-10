#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) 
    {
        if(n == 0 || n == 1)       
        {
            return n;
        }
       int fib1 = 0;
       int fib2 = 1; // base cases
        

        for(int i =2;i<n+1;i++)
        {
            int temp = fib2 + fib1;
            // now store temp and fib2 for next values....
            fib1 = fib2;
            fib2 = temp;
        }

        return fib2;
    }
};