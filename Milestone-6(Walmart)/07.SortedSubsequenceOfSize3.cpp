//GFG Question: https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1/#

class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int N) {
        // Your code here
        
         vector<int> ans;
         
        if(N<3)
        return ans;
        
       int leftmin[N];
       int rightmax[N];
       
       leftmin[0] = arr[0];
       for(int i=1; i<N; i++)
       {
           if(leftmin[i-1]<arr[i])
           leftmin[i]=leftmin[i-1];
           else leftmin[i]=arr[i];
       }
       
       rightmax[N-1] = arr[N-1];
       for(int i=N-2; i>=0; i--)
       {
           if(rightmax[i+1]>arr[i])
           rightmax[i]=rightmax[i+1];
           else rightmax[i]=arr[i];
       }
       
       for(int i=0; i<N; i++)
       {
           if(leftmin[i] < arr[i] && arr[i]< rightmax[i])
           {
               ans.push_back(leftmin[i]);
               ans.push_back(arr[i]);
               ans.push_back(rightmax[i]);
               return ans;
           }
       }
       return ans;
    }
};
