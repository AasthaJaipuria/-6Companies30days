//GFG Question: https://practice.geeksforgeeks.org/problems/longest-arithmetic-progression1019/1/#

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        
        if(n<=2)
        return n;
        
        int ans=2;
        int dp[n][n];
        //dp[i][j] will represent length of AP possible with c.d A[j]-A[i]
        //starting fron i, j and all after j
        
        for(int i=0; i<n-1; i++)
        dp[i][n-1]=2;
        //n-1 is the last index. no sequence can be after it.
        
        for(int j=n-2; j>=1; j--)
        {
            int i=j-1; int k=j+1;
            //We will find i, j, k such that 2*A[j] = A[i]+A[k]
            while(i>=0 && k<=n-1)
            {
                if(A[i]+A[k]<2*A[j])
                {
                    k++;
                }
                else if(A[i]+A[k]>2*A[j])
                {
                    dp[i][j]=2;
                    i--;
                }
                else
                {
                    dp[i][j]=dp[j][k]+1;
                    ans=max(ans, dp[i][j]);
                    i--; k++;
                }
            }
            while(i>=0)
                {
                    dp[i][j]=2;
                    i--;
                }
        }
        return ans;
    }
};
