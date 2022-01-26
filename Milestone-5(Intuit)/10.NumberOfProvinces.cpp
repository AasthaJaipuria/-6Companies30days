//Leetcode Question: https://leetcode.com/problems/number-of-provinces/
// 547. Number of Provinces

class Solution {
public:
    void DFS(int i, vector<vector<int>>& isConnected, int n, bool visited[])
    {
        visited[i]=true;
        for(int j=0; j<n; j++)
        {
            if(isConnected[i][j]==1 &&visited[j]==false)
                DFS(j, isConnected, n, visited);   
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int n = isConnected.size();
        if(n==0)
            return 0;
        
        bool visited[n];
        for(int i=0; i<n; i++)
            visited[i]=false;
        
        for(int i=0; i<n; i++)
        {
            if(visited[i]==false)
            {
                DFS(i, isConnected, n, visited);
                count++;
            }
        }
         return count;   
    }
};
