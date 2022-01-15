//GFG Question: https://practice.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1/

class Solution{
public:
    int minSteps(int D){
        // code here
        D=abs(D);
        if(D==0)
        return 0;
        
        int sum=0;
        int i=1;
        int ans=0;
        while(sum<D)
        {
            sum+=i;
            i++;
            ans++;
        }
        
        if(sum==D)
        return ans;
        
        int dist=sum-D;
        if(dist%2==0)
        return ans;
        if((sum+i-D)%2==0)
        return ans+1;
        return ans+2;
    }
};
