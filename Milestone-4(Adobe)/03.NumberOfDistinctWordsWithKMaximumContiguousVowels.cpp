//GFG Question: https://practice.geeksforgeeks.org/problems/7b9d245852bd8caf8a27d6d3961429f0a2b245f1/1/#

class Solution
{
  public:
    int kvowelwords(int N, int K) {
        // Write Your Code here
        int MOD = 1000000007;
        long long int dp[N+1][K+1];
        
        for(int i=0; i<=K; i++)
        {
            dp[0][i] = 0; //if length of string is 0, then ans 0
        }
        
        dp[1][0] = 21;
        if(K>=1)
        dp[1][1] = 5;
        
        for(int i=2; i<=K; i++)
        {
            dp[1][i] = 0;
        }
        
        for(int i=2; i<=N; i++)
        {
            for(int j=0; j<=K; j++)
            {
                if(j>i)
                dp[i][j] = 0;
                else if(i==j)
                {
                    long long int sum = 1;
                    for(int k=1; k<=i; k++)
                    {
                        sum=(sum*5)%MOD;
                    }
                    dp[i][j] = sum;
                }
                else if(j==0)
                {
                    long long int sum = 0;
                    for(int k=0; k<=K; k++)
                    {
                        sum = (sum+dp[i-1][k])%MOD;
                    }
                    sum = (sum*21)%MOD;
                    dp[i][j] = sum;
                }
                else dp[i][j] = ((dp[i-1][j-1])*5)%MOD;
            }
        }
        
        int ans = 0;
        for(int i=0; i<=K; i++)
        ans= (ans+dp[N][i])%MOD;
        return ans;
    }
};
