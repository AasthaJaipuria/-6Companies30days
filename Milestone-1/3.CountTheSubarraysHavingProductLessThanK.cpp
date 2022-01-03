class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        if(n<1)
        return 0;
        if(n==1)
        return a[0]<k;
        
        if(k==1)
        {
            return 0;
        }
        
        //It is like the sliding window problem
        long long prod=1;
        int ans=0;
        int left=0;
        int right=0;
        while(right<a.size() && left<=right)
        {
            prod=prod*a[right];
            while(prod>=k && left<=right)
            {
                prod=prod/a[left];
                left++;
            }
                
            if(prod<k)
            {
                ans+= (right-left+1);
            }
            right++;
        }
        return ans;
    }
};
