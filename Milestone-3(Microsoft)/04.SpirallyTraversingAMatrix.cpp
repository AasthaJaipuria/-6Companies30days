//GFG question: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/#

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector <int> ans;
        if(matrix.size()==0)
        return ans;
        //right, down, left, up
        int flag=1;
        int i=0, j=0;
        ans.push_back(matrix[i][j]);
        matrix[i][j]=-1; //to mark it as visited;
        while(flag==1)
        {
            flag=0;
            while(j+1<c && matrix[i][j+1]!=-1)
            {
                j=j+1;
                ans.push_back(matrix[i][j]);
                matrix[i][j]=-1; 
                flag=1;
            }
            
            while(i+1<r && matrix[i+1][j]!=-1)
            {
                i=i+1;
                ans.push_back(matrix[i][j]);
                matrix[i][j]=-1;
                flag=1;
            }
            
            while(j-1>=0 && matrix[i][j-1]!=-1)
            {
                j=j-1;
                ans.push_back(matrix[i][j]);
                matrix[i][j]=-1;
                flag=1;
            }
            
            while(i-1>=0 && matrix[i-1][j]!=-1)
            {
                i=i-1;
                ans.push_back(matrix[i][j]);
                matrix[i][j]=-1;
                flag=1;
            }
        }
        return ans;
    }
};
