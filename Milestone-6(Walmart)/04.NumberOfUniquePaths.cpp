//GFG Question: https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1/#

class Solution
{
    public:
    int dp[100][100];
    int DFS(int rowstart, int colstart, int targetRow, int targetCol)
    {
        if(rowstart==targetRow && colstart==targetCol)
        {
            if(dp[rowstart][colstart]==-1)
            dp[rowstart][colstart]=1;
            return dp[rowstart][colstart];
        }
        
        if(dp[rowstart][colstart]!=-1)
        return dp[rowstart][colstart];
        
        int a=0;
        int b=0;
        if(rowstart+1<=targetRow)
        {
            if(dp[rowstart+1][colstart]==-1)
            dp[rowstart+1][colstart]=DFS(rowstart+1, colstart, targetRow, targetCol);
            a = dp[rowstart+1][colstart];
        }
        
        if(colstart+1<=targetCol)
        {
            if(dp[rowstart][colstart+1]==-1)
            dp[rowstart][colstart+1]=DFS(rowstart, colstart+1, targetRow, targetCol);
            b = dp[rowstart][colstart+1];
        }
        
        dp[rowstart][colstart] = a+b;
        return dp[rowstart][colstart];
    }
    
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        
        //start = 0, 0
        //end = a-1, b-1
        
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            dp[i][j]=-1;
        }
        
        return DFS(0, 0, a-1, b-1);
    }
};class Solution
{
    public:
    int dp[100][100];
    int DFS(int rowstart, int colstart, int targetRow, int targetCol)
    {
        if(rowstart==targetRow && colstart==targetCol)
        {
            if(dp[rowstart][colstart]==-1)
            dp[rowstart][colstart]=1;
            return dp[rowstart][colstart];
        }
        
        if(dp[rowstart][colstart]!=-1)
        return dp[rowstart][colstart];
        
        int a=0;
        int b=0;
        if(rowstart+1<=targetRow)
        {
            if(dp[rowstart+1][colstart]==-1)
            dp[rowstart+1][colstart]=DFS(rowstart+1, colstart, targetRow, targetCol);
            a = dp[rowstart+1][colstart];
        }
        
        if(colstart+1<=targetCol)
        {
            if(dp[rowstart][colstart+1]==-1)
            dp[rowstart][colstart+1]=DFS(rowstart, colstart+1, targetRow, targetCol);
            b = dp[rowstart][colstart+1];
        }
        
        dp[rowstart][colstart] = a+b;
        return dp[rowstart][colstart];
    }
    
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        //code here
        
        //start = 0, 0
        //end = a-1, b-1
        
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            dp[i][j]=-1;
        }
        
        return DFS(0, 0, a-1, b-1);
    }
};
