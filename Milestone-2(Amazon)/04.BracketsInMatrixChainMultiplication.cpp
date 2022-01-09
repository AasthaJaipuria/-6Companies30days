//Question on GFG: https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/

class Solution{
    string ans="";
    void optimal_parens(int *s, int i, int j, int n, int m)
    {
        if(i==j)
        ans+=char(i+65);
        else{
            ans+='(';
            int k=*((s+i*m) + j);
            optimal_parens(s, i, k, n, m);
            optimal_parens(s, k+1, j, n, m);
            ans+=')';
        }
    }
public:
    string matrixChainOrder(int p[], int n){
        // code here
        int m[n-1][n-1];
        int s[n-2][n-1];
        
        for(int i=0; i<n-1; i++)
        m[i][i]=0;
        
        for(int l=2; l<=n-1; l++)
        {
            for(int i=0; i<=n-2-l+1; i++)
            {
                int j=i+l-1;
                m[i][j]=INT_MAX;
                for(int k=i; k<j; k++)
                {
                    int multi=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
                    if(multi<m[i][j])
                    {
                        m[i][j]=multi;
                        s[i][j]=k;
                    }
                }
            }
        }

        optimal_parens((int *)s, 0, n-2, n-2, n-1);
        return ans;
    }
};
