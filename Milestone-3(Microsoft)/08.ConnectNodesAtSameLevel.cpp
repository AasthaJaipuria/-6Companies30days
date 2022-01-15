//GFG Question: https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1/#

/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */


class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // Your Code Here
       //Level Order Traversal
       queue <Node*> q;
       if(root==NULL)
       return;
       q.push(root);
       while(!q.empty())
       {
           int queueSize = q.size();
           for(int i=0; i<queueSize; i++)
           {
               Node* temp=q.front();
               q.pop();
               if(i+1<queueSize)
               {
                   temp->nextRight=q.front();
               }
               if(temp->left)
               {
                   q.push(temp->left);
               }
               if(temp->right)
               {
                   q.push(temp->right);
               }
           }
       }
    }  
};
