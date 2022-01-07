//Question on Leetcode: https://leetcode.com/problems/longest-mountain-in-array/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n<3)
            return 0;
        
        int ans=0;
        int i=0;
        
        while(i<n-1)
        {
            int start=-1;
            while(i<n-1 && arr[i+1]<=arr[i])
                i++;
            if(i>=n-1)
                return ans;
            start=i;
            i++;
            
            while(i<n-1 && arr[i+1]>arr[i])
                i++;
            if(i>=n-1)
                return ans;
            if(arr[i+1]==arr[i])
            {
                i++;
                continue;
            }
            
            int end=i+1;
            ans=max(ans, end-start+1);
            while(i<n-1 && arr[i+1]<arr[i]) 
            {
                end=i+1;
                ans=max(ans, end-start+1);
                i++;
            }
                
        }
        return ans;
    }
};
