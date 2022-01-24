//Leetcode Questions: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// 1011. Capacity To Ship Packages Within D Days

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        //Same as Pages Allocation Problem
        
        int low=0;
        int high=0;
        int len=weights.size();
        if(len<=0)
            return 0;
        
        if(days<=0)
            return -1;
        
        for(int i=0; i<len; i++)
        {
            high+=weights[i];
            low=weights[i]>low?weights[i]:low;
        }
        
        if(days==1)
            return high;
        if(days==len)
            return low;
        
        int ans=0;
        
        while(low<=high)
        {
           int mid = (high-low)/2+low;
            int sum=0;
            int dayNo=1;
            for(int i=0; i<len; i++)
            {
                if(sum+weights[i]<=mid)
                    sum+=weights[i];
                else {
                    sum=weights[i];
                    dayNo++;
                }
            }
            if(dayNo<=days)
            {
                ans= mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
