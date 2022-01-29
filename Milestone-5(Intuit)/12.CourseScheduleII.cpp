//Leetcode Question: https://leetcode.com/problems/course-schedule-ii/
//210. Course Schedule II

class Solution {
public:
    
    int DFS(int start, vector<vector<int>> &adj, bool visited[], bool dfsVisited[], stack<int> &st)
    {
        visited[start] = true;
        dfsVisited[start] = true;
        for(int i=0; i<adj[start].size(); i++)
        {
            if(dfsVisited[adj[start][i]]==true)
            {
                return 1;
            }
            if(visited[adj[start][i]]==false)
            {
                if(DFS(adj[start][i], adj, visited, dfsVisited, st)==1)
                {
                    return 1;
                }
            }
        }
        dfsVisited[start]=false;
        st.push(start);
        return 0;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //Create adjacency list
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        stack<int> st;
        //Create Topological Order
        bool visited[numCourses];
        bool dfsVisited[numCourses];
        for(int i=0; i<numCourses; i++)
        {
            visited[i] = false;
            dfsVisited[i] = false;
        }
        
         vector<int> ans;
        for(int i=0; i<numCourses; i++)
        {
            if(visited[i]==false)
            {
                if(DFS(i, adj,visited, dfsVisited, st)==1)
                    return ans;
            }
        }
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
