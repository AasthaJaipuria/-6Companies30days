//GFG Question: https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        if(N==1)
        {
            if(arr[0]==0)
            return 1;
            else return 0;
        }
        
        if(N==2)
        return arr[0]==arr[1];
        
        int sum=0;
        for(int i=0; i<N; i++)
        sum+=arr[i];
        
        //We have to find a subarray such that it's sum is sum/2;
        if(sum%2!=0)
        return 0;
        
        sum=sum/2;
        int dp[N+1][sum+1];
        
        for(int i=0; i<N+1; i++)
        {
            dp[i][0]=1;
        }
        for(int i=1; i<sum+1; i++)
        {
            dp[0][i]=0; //with 0 elements, only 0 sum is possible;
        }
        
        for(int i=1; i<N+1; i++)
        {
            for(int j=1; j<sum+1; j++)
            {
                dp[i][j]=dp[i-1][j];
                if(dp[i][j]==0)
                {
                    if(arr[i-1]<=j)
                    {
                        if(dp[i-1][j-arr[i-1]]==1)
                        dp[i][j]=1;
                    }
                }
            }
        }
        for(int i=0; i<N+1; i++)
        {
            if(dp[i][sum]==1)
            return 1;
        }
        return 0;
    }
};
