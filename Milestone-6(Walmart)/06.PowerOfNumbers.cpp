//GFG Question: https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1/?company[]=Walmart&company[]=Walmart&page=1&query=company[]Walmartpage1company[]Walmart

class Solution{
    public:
    //You need to complete this fucntion
    
    long long exponent(int x, int y)
    {
        if(y==0)
        return 1;
        if(x==0)
        return 0;
        long long temp = int(exponent(x, y/2))%1000000007;
        if(y%2==0)
        return (temp*temp)%1000000007;
        else return (((x*temp)%1000000007)*temp)%1000000007;
    }
    
    long long power(int N,int R)
    {
       //Your code here
        int rev=0;
        int orig = N;
        while(orig)
        {
            rev=(rev*10)+(orig%10);
            orig/=10;
        }
        return exponent(N, rev);
    }
};
