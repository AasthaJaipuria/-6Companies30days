//GFG Question: https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/#

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isCycle(int Node, vector<vector<int>>& adj, bool vis[], bool dfsVis[])
    {
      //not passing adj as reference was giving TLE
        vis[Node]=1;
        dfsVis[Node]=1;
        for(int i=0; i<adj[Node].size(); i++)
        {
            if(dfsVis[adj[Node][i]])
            return true;
            if(!vis[adj[Node][i]])
            {
                if(isCycle(adj[Node][i], adj, vis, dfsVis))
                return true;
            }
        }
        dfsVis[Node]=0;
        return false;
    }
    
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector <vector<int>> adj(N);
	    for(int i=0; i<prerequisites.size(); i++)
	    {
	        adj[prerequisites[i].second].push_back(prerequisites[i].first);
	    }
	    
	    
	    bool vis[N];
	    bool dfsVis[N];
	    memset(vis, 0, sizeof(vis));
	    memset(dfsVis, 0, sizeof(dfsVis));
	    
	    for(int i=0; i<N; i++)
	    {
	        if(!vis[i])
	        {
	            if(isCycle(i, adj, vis, dfsVis))
	            return false; //if it is a cycle, then work can't be done
	        }
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
