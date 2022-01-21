//GFG Question: https://practice.geeksforgeeks.org/problems/word-search/1/#

class Solution {
public:

    bool func(vector<vector<char>>& board, int rows, int cols, int i, int j, map <pair<int, int>, bool> &visited, int k, string &word)
    {
        if(k>=word.length())
        return true;
        
        //right
        if(j+1<cols)
        {
            pair <int, int> p;
            p=make_pair(i, j+1);
            if(board[i][j+1]==word[k] && visited[p]!=true)
            {
                visited[p]=true;
                if(func(board, rows, cols, i, j+1, visited, k+1, word))
                return true;
                else visited[p]=false;
            }
        }
        //left
        if(j-1>=0)
        {
            pair <int, int> p;
            p=make_pair(i, j-1);
            if(board[i][j-1]==word[k] && visited[p]!=true)
            {
                visited[p]=true;
                if(func(board, rows, cols, i, j-1, visited, k+1, word))
                return true;
                else visited[p]=false;
            }
        }
        //up
        if(i-1>=0)
        {
            pair <int, int> p;
            p=make_pair(i-1, j);
            if(board[i-1][j]==word[k] && visited[p]!=true)
            {
                visited[p]=true;
                if(func(board, rows, cols, i-1, j, visited, k+1, word))
                return true;
                else visited[p]=false;
            }
        }
        //down
        if(i+1<rows)
        {
            pair <int, int> p;
            p=make_pair(i+1, j);
            if(board[i+1][j]==word[k] && visited[p]!=true)
            {
                visited[p]=true;
                if(func(board, rows, cols, i+1, j, visited, k+1, word))
                return true;
                else visited[p]=false;
            }
        }
        return false;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int rows=board.size();
        int cols=board[0].size();
        if(rows*cols<word.length())
        return false;
        
        if(word.length()==0)
        return true;
        
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(board[i][j]==word[0])
                {
                    map <pair<int, int>, bool> visited;
                    pair<int, int> p1;
                    p1=make_pair(i, j);
                    visited[p1]=true;
                   if(func(board, rows, cols, i, j, visited, 1, word)==true)
                   return true;
                }
            }
        }
        return false;
    }
};
