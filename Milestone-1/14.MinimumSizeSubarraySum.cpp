//Leetcode Question Link : https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len=nums.size();
        int start=0; int end=0; int minLength=len+1;
        
        if(len<=0)
            return 0;
        int sum=0;
        for(int end=0; end<len; end++)
        {
            sum+=nums[end];
            if(sum>=target)
            {
                minLength=(minLength>(end-start+1))?(end-start+1):minLength;
                //cout<<minLength<<" ";
                while(sum-nums[start]>=target &&start<=end)
                {
                    sum-=nums[start];
                    start++;
                    minLength=(minLength>(end-start+1))?(end-start+1):minLength;
                    //cout<<minLength<<" ";
                }
            }
        }
        if(minLength<len+1)
            return minLength;
        return 0; 
    }
};
