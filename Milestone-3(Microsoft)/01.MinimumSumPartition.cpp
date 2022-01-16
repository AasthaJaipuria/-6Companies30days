//GFG Question: https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0; i<n; i++)
	    {
	        sum+=arr[i];
	    }
	    int x=sum/2+1; //no. of columns
	    int y=n+1;  //no. of rows
	    bool dp[y][x];
	    
	    for(int i=0; i<y; i++)
	    dp[i][0]=true; //0 sum can be made from every set because, every set has an empty subset
	    
	    for(int i=1; i<x; i++)
	    dp[0][i]=false; //empty subset can't make any sum except 0
	    
	    for(int i=1; i<y; i++)
	    {
	        for(int j=1; j<x; j++)
	        {
	            dp[i][j]=dp[i-1][j]; 
	            if(dp[i][j]==false)
	            {
	                if(arr[i-1]<=j)
	                dp[i][j]=dp[i-1][j-arr[i-1]];
	            }
	        }
	    }
	    
	    int ans=INT_MAX;
	    for(int i=0; i<x; i++)  //traverse last row
	    {
	        if(dp[y-1][i]==true)
	        {
	           ans=min(ans, sum-2*i); 
	        }
	    }
	    return ans;
	} 
};
