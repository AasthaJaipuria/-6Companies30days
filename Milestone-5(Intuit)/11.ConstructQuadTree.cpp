//LeetCode Question: https://leetcode.com/problems/construct-quad-tree/
//427. Construct Quad Tree

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* func(vector<vector<int>> &grid, int startI, int startJ, int n)
    {
        if(n==0)
            return NULL;
        if(n==1)
        {
            Node *root;
            int val;
            if(grid[startI][startJ]==1)
                val=true;
            else val=false;
            root = new Node(val, true);
            return root;
        }
        
        int sum = 0;
        for(int i=startI; i<startI+n; i++)
        {
            for(int j=startJ; j<startJ+n; j++)
            {
                sum+=grid[i][j];
            }
        }
        
        if(sum==0)
        {
            Node* root = new Node(false, true);
            return root;
        }
        
        if(sum==n*n)
        {
            Node *root = new Node(true, true);
            return root;
        }
        else
        {
            Node *root = new Node();
            int factor = n/2;
            root->topLeft = func(grid, startI, startJ, factor);
            root->topRight = func(grid, startI, startJ+factor, factor);
            root->bottomLeft = func(grid, startI+factor, startJ, factor);
            root->bottomRight = func(grid, startI+factor, startJ+factor, factor);
            return root;
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        int startI = 0;
        int startJ = 0;
        int factor = n;
        return func(grid, 0,0, n);
    }
};
