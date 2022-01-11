//Leetcode Question: https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //BFS is used.
        int m=grid.size();
        if(m<=0)
            return 0;
        int n=grid[0].size();
        
        int time=0;
        
        queue<pair<int, int>> q;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            { 
                if(grid[i][j]==2)
                {
                    pair<int, int>p1;
                    p1=make_pair(i, j);
                    q.push(p1);
                }
            }
        }
        
        /* 4 directions:
        up [i-1][j]
        down [i+1][j]
        right [i][j+1]
        left [i][j-1]  */
        
        while(!q.empty())
        {
            int flag=0;
            int queuesize = q.size();
            
            for(int k=0; k<queuesize; k++)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(i-1>=0 && grid[i-1][j]==1)
                {
                    grid[i-1][j]=2;
                    flag=1;
                    pair <int, int> p1;
                    p1 = make_pair(i-1, j);
                    q.push(p1);
                }
                if(i+1<m && grid[i+1][j]==1)
                {
                    grid[i+1][j]=2;
                    flag=1;
                    pair <int, int> p1;
                    p1 = make_pair(i+1, j);
                    q.push(p1);
                }
                if(j+1<n && grid[i][j+1]==1)
                {
                    grid[i][j+1]=2;
                    flag=1;
                    pair <int, int> p1;
                    p1 = make_pair(i, j+1);
                    q.push(p1);
                }
                if(j-1>=0 && grid[i][j-1]==1)
                {
                    grid[i][j-1]=2;
                    flag=1;
                    pair <int, int> p1;
                    p1 = make_pair(i, j-1);
                    q.push(p1);
                } 
            }
            if(flag==1)
                time++;
        } 
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return time;
    }
};
