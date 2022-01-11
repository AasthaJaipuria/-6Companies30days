//GFG Question: https://practice.geeksforgeeks.org/problems/burning-tree/1/#

class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        //we need to store the parent pointers to apply BFS
        
        if(root==NULL)
        return 0;
        map <Node*, Node*> m;
        Node *start=root;
        queue <Node*> q; 
        q.push(start);
        Node* t=NULL;
        map <Node*, bool> burnt;
        
        while(!q.empty())
        {
            Node* temp=q.front();
            if(temp->data==target)
            t=temp;
            burnt[temp]=false;
            q.pop();
            if(temp->left)
            {
                m[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right)
            {
                m[temp->right]=temp;
                q.push(temp->right);
            }
        }
        
        //till now we have mapped children to their parents.
        //now we will apply bfs starting from target.
        //I can use the same queue q because now it is empty
        
        int time=0;
        burnt[t]=true;
        q.push(t);
        
        while(!q.empty())
        {
            int flag=0;
            int queuesize = q.size();
            for(int i=0; i<queuesize; i++)
            {
                Node* temp=q.front();
                q.pop();
                if(temp->left && burnt[temp->left]==false)
                {
                    burnt[temp->left]=true;
                    q.push(temp->left);
                    flag=1;
                }
                
                if(temp->right && burnt[temp->right]==false)
                {
                    burnt[temp->right]=true;
                    q.push(temp->right);
                    flag=1;
                }
                
                if(m[temp] && burnt[m[temp]]==false)
                {
                    burnt[m[temp]]=true;
                    q.push(m[temp]);
                    flag=1;
                }
            }
            if(flag==1)
            time++;
        }
        return time;
    }
};
