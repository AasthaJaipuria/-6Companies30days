//GFG Question: https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1/#

class Solution {
public:
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    int dp[n][n];
	    for(int i=0; i<n; i++)
	    dp[i][i] = A[i];
	    
	    for(int i=0; i<n-1; i++)
	    dp[i][i+1] = max(A[i], A[i+1]);
	    
	    for(int gap=2; gap<n; gap++)
	    {
	        for(int i=0; i+gap<n; i++)
	        {
	            //dp[i][i+gap]
	            int j=i+gap;
	            dp[i][j] = max(A[i]+min(dp[i+2][j], dp[i+1][j-1]), A[j]+min(dp[i+1][j-1], dp[i][j-2]));
	  //If I pick i, other will pick in such a way that i am left with min, same is the case with j          
	        }
	    }
	    return dp[0][n-1];
    }
};
