//GFG Question: https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1/#

/*
delete n nodes after m nodes
  The input list will have at least one element  
  Node is defined as 

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/
class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
        //Add code here 
        if(head==NULL)
        return;
        
        Node* start=head;
        
        while(start)
        {
            for(int i=0; i<M-1; i++)
            {
                start=start->next;
                if(start==NULL)
                return;
            }
            
            for(int i=0; i<N; i++)
            {
                if(start->next==NULL)
                return;
                start->next=start->next->next;
            }
            if(start->next==NULL)
                return;
                start=start->next;
        }
    }
};
