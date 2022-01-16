//GFG Question: https://practice.geeksforgeeks.org/problems/alien-dictionary/1/

class Solution{
    public:
    stack <int> st;
    
    void Topological(int start, vector<char> *adj, int K, int visited[])
    {
        visited[start]=1;
        for(int i=0; i<adj[start].size(); i++)
        {
            if(visited[adj[start][i]-'a']==0)
            Topological(adj[start][i]-'a', adj, K, visited);
        }
        st.push(start);
    }
    
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<char> adj[K]; 
        for(int i=0; i<N-1; i++)
        {
            int len=min(dict[i].length(), dict[i+1].length());
            int j=0;
            while(j<len && dict[i][j]==dict[i+1][j])
            {
                j++;
            }
            
            if(j<len && dict[i][j]!=dict[i+1][j])
            {
                adj[dict[i][j]-'a'].push_back(dict[i+1][j]);
            }
        }
        
        int visited[K];
        memset(visited, 0, sizeof(visited));
        
        for(int i=0; i<K; i++)
        {
            if(visited[i]==0)
            Topological(i, adj, K, visited);
        }
        
        string ans="";
        while(!st.empty())
        {
            char character = char(st.top())+'a';
            st.pop();
            ans+=character;
        }
        
        return ans;
    }
};
