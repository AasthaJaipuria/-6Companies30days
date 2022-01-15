//GFG Question: https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/

class Solution
{
    public:
    void DFS(vector<vector<int>>& grid, int n, int m, int i, int j, int &temp)
    {
        grid[i][j]=-1;
        temp++;
        if(i+1<n && grid[i+1][j]==1)
        DFS(grid, n, m, i+1, j, temp);
        if(i-1>=0 && grid[i-1][j]==1)
        DFS(grid, n, m, i-1, j, temp);
        if(j+1<m && grid[i][j+1]==1)
        DFS(grid, n, m, i, j+1, temp);
        if(j-1>=0 && grid[i][j-1]==1)
        DFS(grid, n, m, i, j-1, temp);
        if(i-1>=0 && j-1>=0 && grid[i-1][j-1]==1)
        DFS(grid, n, m, i-1, j-1, temp);
        if(i-1>=0 && j+1<m && grid[i-1][j+1]==1)
        DFS(grid, n, m, i-1, j+1, temp);
        if(i+1<n && j+1<m && grid[i+1][j+1]==1)
        DFS(grid, n, m, i+1, j+1, temp);
        if(i+1<n && j-1>=0 && grid[i+1][j-1]==1)
        DFS(grid, n, m, i+1, j-1, temp);
        
    }
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    int temp=0;
                    DFS(grid, n, m, i, j, temp);
                    count=temp>count?temp:count;
                }
            }
        }
        return count;
    }
};
