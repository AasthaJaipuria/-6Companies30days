//GFG Question: https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    if(n==1)
	    return arr[0];
	    int sum=0;
	    for(int i=0; i<n; i++)
	    sum+=arr[i];
	    int SUM=sum;
	    sum=sum/2;
	    int dp[n+1][sum+1];
	    
	    for(int i=0; i<n+1; i++)
	    dp[i][0]=1;
	    
	    for(int i=1; i<sum+1; i++)
	    dp[0][i]=0;
	    
	    for(int i=1; i<n+1; i++)
	    {
	        for(int j=1; j<sum+1; j++)
	        {
	            dp[i][j]=dp[i-1][j];
	            if(dp[i][j]==0)
	            {
	                if(arr[i-1]<=j)
	                {
	                    dp[i][j]=dp[i-1][j-arr[i-1]];
	                }
	            }
	        }
	    }
	    
	    int ans = INT_MAX;
	    for(int i=0; i<sum+1; i++)
	    {
	        if(dp[n][i]==1)
	        ans=min(ans, abs(SUM-2*i));
	    }
	    return ans;
	} 
};
