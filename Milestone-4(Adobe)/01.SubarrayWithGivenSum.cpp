//GFG Question: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        long long sum=0;
        int start=0;
        for(int i=0; i<n; i++)
        {
            sum+=arr[i];
            if(sum<s)
            continue;
            while(sum>s && start<i)
            {
                sum-=arr[start];
                start++;
            }
            if(sum==s)
            {
                vector<int> ans;
                ans.push_back(start+1);
                ans.push_back(i+1);
                return ans;
            }
        }
        vector<int> ans;
        ans.push_back(-1);
        return ans;
    }
};
