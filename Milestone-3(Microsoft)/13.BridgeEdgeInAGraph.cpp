//GFG Question: https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1#

class Solution
{
	public:
	
	void DFS(int start, vector<int> adj[], int visited[])
	{
	    //cout<<start<<" ";
	    visited[start] = 1;
	    for(int i=0; i<adj[start].size(); i++)
	    {
	        if(visited[adj[start][i]]==0)
	        DFS(adj[start][i], adj, visited);
	    }
	    return;
	}
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        
        int visited[V];
        memset(visited, 0, sizeof(visited));
        
        queue<int> connected;
        
        DFS(c, adj, visited);
        for(int i=0; i<V; i++)
        {
            if(visited[i]==1)
            connected.push(i);
        }
        
        //Delete d from adj[c] and c from adj[d]
        vector<int>::iterator it = adj[c].begin();
        while (it != adj[c].end()) {          
           if(*it == d)         
           {
                adj[c].erase(it); 
                break;
            }   
               it++;
        }
         
        it = adj[d].begin();
        while (it != adj[d].end()) {           
           if(*it == c)      
           {
                adj[d].erase(it); 
                break;
            }   
               it++;
        }
        
        //We call DFS from one node, if all the nodes which were previously 
        //connected are still connected, then not a bridge else a bridge
        
        memset(visited, 0, sizeof(visited));
        
        DFS(c, adj, visited);
        
        while(!connected.empty())
        {
            if(visited[connected.front()]==1)
            connected.pop();
            else return 1;
        }
        
        return 0;
    }
};
