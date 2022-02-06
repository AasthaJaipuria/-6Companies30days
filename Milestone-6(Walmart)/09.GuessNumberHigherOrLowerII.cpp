//Leetcode Question: https://leetcode.com/problems/guess-number-higher-or-lower-ii/
//375. Guess Number Higher or Lower II

class Solution {
public:
    int getMoneyAmount(int n) {
        
        if(n==1)
            return 0;
        if(n==2)
            return 1;
        
        int dp[n+2][n+1];
        
        memset(dp, 0, sizeof(dp));
        
        for(int i=1; i<n; i++)
        {
            dp[i][i+1]=i;
        }
        
        for(int len=3; len<=n; len++)
        {
            for(int start=1; start<=n-len+1; start++)
            {
                int end=start+len-1;
                int ans= INT_MAX;
                for(int pivot=start; pivot<=end; pivot++)
                {
                    ans = min(ans, pivot+max(dp[start][pivot-1], dp[pivot+1][end]));
                }
                dp[start][end]=ans;
            }
        }
        return dp[1][n];
    }
};
