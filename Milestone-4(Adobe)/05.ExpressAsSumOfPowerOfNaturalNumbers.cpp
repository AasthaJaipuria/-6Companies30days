//GFG Question: https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1#

class Solution{
    public:
    long long dp[1001][1001];
    
    int func(int startIdx, int n, int arr[], int len)
    {
        if(dp[startIdx][n]!=-1)
        return dp[startIdx][n];
    if(n==0)
    {
        dp[startIdx][n]=1;
        return 1;
    }
    
    if(arr[startIdx]==n)
    {
         dp[startIdx][n]=1;
        return 1;
    }
 
    if(arr[startIdx]>n)
    {
        dp[startIdx][n]=0;
        return 0;
    }
    
    if(startIdx+1<len)
    {
        int a1, a2;
        if(dp[startIdx+1][n]!=-1)
        a1 = dp[startIdx+1][n];
        else a1 = func(startIdx+1, n, arr, len)%1000000007;
        if(dp[startIdx+1][n-arr[startIdx]]!=-1)
        a2 = dp[startIdx+1][n-arr[startIdx]];
        else a2 = func(startIdx+1, n-arr[startIdx], arr, len)%1000000007;
        dp[startIdx][n]=(a1+a2)%1000000007;
        return dp[startIdx][n];
    }
    dp[startIdx][n]=0;
    return 0;
    }
    
    int numOfWays(int n, int x)
    {
        // code here
        float limit = pow(n, double(1)/double(x));
        
        int lim = int(limit);
        if(lim==0)
        return 0;
        
        int arr[lim+1];
        
        for(int i=0; i<lim+1; i++)
        {
            arr[i] = pow(i, x);
        }
        memset(dp, -1, sizeof(dp));
        int ans = func(1, n, arr, lim+1)%1000000007; 
        return ans;
    }
};
