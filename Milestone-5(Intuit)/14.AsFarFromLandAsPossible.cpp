//Leetcode Question: https://leetcode.com/problems/as-far-from-land-as-possible/
//1162. As Far from Land as Possible

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        
        //In this method, we are checking 1 to 0 i.e. land to water. The aim of land is to get farthermost water.
        //We will mark 0's as 1's so that only the nearest land to the water is considered as given in the question.
        
        //We will use BFS
        queue <pair<int, int>> q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    q.push(make_pair(i, j));
                }
            }
        }
        
        if(q.empty() || q.size()==n*n)
            return -1; //either all 1's or all 0's
        
        int Level = -1;
        while(!q.empty())
        {
            Level++;
            int queueSize = q.size();
            for(int k=0; k<queueSize; k++)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                //Now visit the neighbours. Diagonal dir have dist 2 so not cosidering those. 
                //As we are incrementing ans by 1 only at a time. They will be considered in next level.
                
                //up
                if(i-1>=0 && grid[i-1][j]==0)
                {
                    grid[i-1][j]=1;
                    q.push(make_pair(i-1, j));
                }
                
                //down
                if(i+1<n && grid[i+1][j]==0)
                {
                    grid[i+1][j]=1;
                    q.push(make_pair(i+1, j));
                }
                
                //right
                if(j+1<n && grid[i][j+1]==0)
                {
                    grid[i][j+1]=1;
                    q.push(make_pair(i, j+1));
                }
                
                //left
                if(j-1>=0 && grid[i][j-1]==0)
                {
                    grid[i][j-1]=1;
                    q.push(make_pair(i, j-1));
                }
            }
        }
        return Level;
    }
};
