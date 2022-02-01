//Leetcode Question: https://leetcode.com/problems/koko-eating-bananas/
//875. Koko Eating Bananas

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int mini = 1; //minimum bananas to be eaten, 1 is without taking h into consideration
        int maxi = *max_element(piles.begin(), piles.end());
        
        if(n==h)
            return maxi;
        
        int ans = maxi;
        
        while(mini<=maxi)
        {
            int mid = (maxi-mini)/2+mini;
            
            int sumK = 0;
        
            for(int i=0; i<n; i++)
            {
                int hours = piles[i]/mid;
                if(hours*mid<piles[i])
                    hours++;
                sumK+=hours;
            }
            
            if(sumK>h) //very less speed imagined, increase the speed
            {
                mini = mid+1;
            }
            
            if(sumK<=h) //condition staisified, but try to minimize
            {
                ans = min(mid, ans);
                maxi = mid-1;
            }
        }
        return ans;
    }
};
