//Leetcode Question: https://leetcode.com/problems/pacific-atlantic-water-flow/
// 417. Pacific Atlantic Water Flow

class Solution {
public:
    int **visited;
    
    void DFSpacific(vector<vector<int>>& heights, int i, int j, int rows, int cols)
    {
        visited[i][j] = 1;
        int val=heights[i][j];
        //left
        if(j-1>=0 && visited[i][j-1]==0 && heights[i][j-1]>=val)
            DFSpacific(heights, i, j-1, rows, cols);
        //right
        if(j+1<cols && visited[i][j+1]==0 && heights[i][j+1]>=val)
            DFSpacific(heights, i, j+1, rows, cols);
        //up
        if(i-1>=0 && visited[i-1][j]==0 && heights[i-1][j]>=val)
            DFSpacific(heights, i-1, j, rows, cols);
        //down
        if(i+1<rows && visited[i+1][j]==0 && heights[i+1][j]>=val)
            DFSpacific(heights, i+1, j, rows, cols);
    }
    
    void DFSatlantic(vector<vector<int>>& heights, int i, int j, int rows, int cols)
    {
        if(visited[i][j]==0)
        visited[i][j] = 2;
        else if(visited[i][j]==1)
            visited[i][j]=3;
        int val=heights[i][j];
        //left
        if(j-1>=0 && (visited[i][j-1]==0 || visited[i][j-1]==1) && heights[i][j-1]>=val)
            DFSatlantic(heights, i, j-1, rows, cols);
        //right
        if(j+1<cols && (visited[i][j+1]==0 || visited[i][j+1]==1)&& heights[i][j+1]>=val)
            DFSatlantic(heights, i, j+1, rows, cols);
        //up
        if(i-1>=0 && (visited[i-1][j]==0 || visited[i-1][j]==1) && heights[i-1][j]>=val)
            DFSatlantic(heights, i-1, j, rows, cols);
        //down
        if(i+1<rows && (visited[i+1][j]==0 || visited[i+1][j]==1) && heights[i+1][j]>=val)
            DFSatlantic(heights, i+1, j, rows, cols);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //instead of flowing water from cell to ocean, we will take ocean to cell
        //so conditions will reverse. 
        //from ocean to cell, water will flow only if adjacent cell is greater
        vector<vector<int>> ans;
        int rows = heights.size();
        if(rows<=0)
            return ans;
        int cols = heights[0].size();
        if(cols<=0)
            return ans;
        
        if(rows==1 || cols==1)
        {
            for(int i=0; i<rows; i++)
            {
                for(int j=0; j<cols; j++)
                {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    ans.push_back(v);
                }
            }
            return ans;
        }
        
        visited = new int*[rows];
        
        for(int i=0; i<rows; i++)
        {
            visited[i] = new int [cols];
        }
        
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
                visited[i][j]=0;
        }
        //DFS will be called from top row(row 0) and left col(col 0) for pacific ocean
        for(int i=0; i<cols; i++)
        {
            if(visited[0][i]==0)
            DFSpacific(heights, 0, i, rows, cols);
        }
        
        for(int i=0; i<rows; i++)
        {
            if(visited[i][0]==0)
                DFSpacific(heights, i, 0, rows, cols);
        }
        
        //DFS will be called for bottom row(row number rows-1) and rightmost column(column no cols-1)
        //for atlantic ocean
        for(int i=0; i<cols; i++)
        {
            if(visited[rows-1][i]==0 || visited[rows-1][i]==1)
                DFSatlantic(heights, rows-1, i, rows, cols);
        }
        
        for(int i=0; i<rows; i++)
        {
            if(visited[i][cols-1]==0 || visited[i][cols-1]==1)
                DFSatlantic(heights, i, cols-1, rows, cols);
        }
        
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(visited[i][j]==3)
                {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    ans.push_back(v);
                }
            }
        }
         return ans;   
    }
};
