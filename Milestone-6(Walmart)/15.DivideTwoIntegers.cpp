//Leetcode Question: https://leetcode.com/problems/divide-two-integers/
// 29. Divide Two Integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;
        int a = abs(dividend);
        int b = abs(divisor);
        int res =0;
        while(a-b>=0)
        {
               int x=0;
        while(a-(b<<1<<x)>=0)
            x++;
        res += 1<<x;
        a -= b<<x;
        }
        
        if((dividend>=0)==(divisor>=0));
        return res;
        return -1*res;
    }
};
