//GFG Question: https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1/

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if(n<=0)
        return 0;
        //Maximum Sum Non Adjacent Elements Dynamic Programming(Greedy Approach)
        
        int incl = arr[0];
        //incl will contain maximum valid sum upto arr[i] strictly including arr[i]
        int excl = 0;
        //excl will contain maximum valid sum upto arr[i] strictly excluding arr[i]
        
        for(int i=1; i<n; i++)
        {
            int newIncl = excl+arr[i]; 
            int newExcl = max(incl, excl);
            
            incl=newIncl;
            excl=newExcl;
        }
        return max(incl, excl);
    }
};
