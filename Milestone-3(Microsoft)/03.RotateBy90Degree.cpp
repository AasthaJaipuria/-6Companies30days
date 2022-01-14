//GFG Question: https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/

void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    int N=matrix.size();
    if(N<=1)
    return;
    
    //first we take transpose
    for(int i=0; i<N; i++)
    {
        for(int k=i+1; k<N; k++)
        {
            swap(matrix[i][k], matrix[k][i]);
        }
    }
    
    //then we reverse the position of rows from top to down
    int j=N-1;
    for(int i=0; i<N/2; i++)
    {
        swap(matrix[i], matrix[j]);
        j--;
    }
}
