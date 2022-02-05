//GFG Question: https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1/

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    int sum(Node *node)
    {
        if(node==NULL)
        return 0;
        
        int a = sum(node->right);
        int b = sum(node->left);
        int x = node->data;
        node->data = a+b;
        return a+b+x;
    }
    
    void toSumTree(Node *node)
    {
        // Your code here
        sum(node);
        return;
    }
};
