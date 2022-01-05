//Question on GFG: https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1#

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int len=nums.size();
        if(len%2!=0)
        return false;
        
        int arr[k];
        for(int i=0; i<k; i++)
        arr[i]=0;
        
        for(int i=0; i<len; i++)
        {
            arr[nums[i]%k]++;
        }
        
        /*for(int i=0; i<k; i++)
        {
            cout<<arr[i]<<" ";
        }
         cout<<"\n"; */  
        
        int i=1, j=k-1;
        while(i<=j)
        {
            if(i==j)
            {
                if(arr[i]%2==0);
                else return false;
            }
            else if((arr[i]==arr[j]))
            {
                if((arr[i]*i + arr[j]*j)%k==0);
                else return false;
            }
            else return false;
            i++;
            j--;
        }
        return true;
    }
};
