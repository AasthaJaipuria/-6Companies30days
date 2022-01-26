//GFG Question: https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/#

class Solution
{
    public:
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<vector<string>> v(n+1);
        string s = "";
        v[0].push_back(s);
        if(n<=0)
        return v[0];
        
        s="()";
        v[1].push_back(s);
        if(n==1)
        return v[1];
        
      //new string will be ( + insideval ) + outsideval
        for(int i=2; i<=n; i++)
        {
            int k=0; //outside
            for(int j=i-1; j>=0; j--) //inside
            {
                for(int l=0; l<v[j].size(); l++)
                {
                    string s = "(" + v[j][l] + ")";
                    for(int m=0; m<v[k].size(); m++)
                    {
                        v[i].push_back(s+v[k][m]);
                    }
                }
                k++;
            }
        }
        return v[n];
    }
};
