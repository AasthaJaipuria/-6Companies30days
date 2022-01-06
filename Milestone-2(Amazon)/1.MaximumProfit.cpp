//Question on GFG https://practice.geeksforgeeks.org/problems/maximum-profit4657/1

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        int dp[K+1][N];
        for(int i=0; i<N; i++)
        dp[0][i] = 0;
        for(int i=1; i<K+1; i++)
        dp[i][0]=0;
        
        for(int i=1; i<K+1; i++)
        { 
        //We want max of previous value(same row, previous column)
        //and all diagonal elements+new transaction
        //(previous row, all columns before)+(A[j]-A[column of selected previous column])
            int temp=INT_MIN;
            for(int j=1; j<N; j++)
            {
               /* for(int k=0; k<=j-1; k++)
                {
                    if(A[j]-A[k]>=0)
                    temp=max(temp, A[j]-A[k]+dp[i-1][k]);
                } */
                
                temp=max(temp, dp[i-1][j-1]-A[j-1]);
                dp[i][j]=max(dp[i][j-1], temp+A[j]);
            }
        }
        return dp[K][N-1];
    }
};
