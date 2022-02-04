//Leetcode Question: https://leetcode.com/problems/path-with-maximum-probability/
// 1514. Path with Maximum Probability

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        //use dijkstra
        
        //make an adjacency list
        vector<vector<pair<int, double>>> adj(n);
        int edgeNos = edges.size();
        for(int i=0; i<edgeNos; i++)
        {
            adj[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
            adj[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
        }
        
        vector<bool> visited(n, false);
        
        priority_queue <pair<double, int>> maxheap;
        
        vector<double> prob (n,0);
        prob[start] = 1;
        
        maxheap.push(make_pair(1, start));
        
        while(!maxheap.empty())
        {
          double currentProb =  maxheap.top().first;
          int currentIdx = maxheap.top().second;
            if(currentIdx==end)
                break;
            maxheap.pop();
            if(visited[currentIdx]==false)
            {
                for(int i=0; i<adj[currentIdx].size(); i++)
                {
                    double nextProb = currentProb*(adj[currentIdx][i].second);
                    if(visited[adj[currentIdx][i].first]==false && nextProb>prob[adj[currentIdx][i].first])
                    {
                        prob[adj[currentIdx][i].first]=nextProb;
                        maxheap.push(make_pair(nextProb, adj[currentIdx][i].first));
                    }
                }
                
                visited[currentIdx] = true;
            }
             else continue;   
        }
        return prob[end];
    }
};
