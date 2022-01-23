//Leetcode Question(410): https://leetcode.com/problems/split-array-largest-sum/
//Time Complexity: O(n*log(sum)); n->number of elements in array, sum->sum of all elements of array, log is base2

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        
        int low = *max_element(nums.begin(), nums.end());
        int high = 0;
        for(int i=0; i<n; i++)
                high+=nums[i];
        
        if(m==n)
            return low;
        
        if(m==1)
        {
            return high;  //only one subarray, which means the whole array, hence sum
        }
        
        int mid = (high-low)/2+low;
        int ans = high;
        
        while(high>=low)
        {
            mid = (high-low)/2+low;
            int arrayNo = 1;
            int sum=0;
            for(int i=0; i<n; i++)
            {
                if(sum+nums[i]<=mid)
                    sum+=nums[i];
                else{
                    arrayNo++;
                    sum=nums[i];
                }
            }
            if(arrayNo<=m)
            {
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};
