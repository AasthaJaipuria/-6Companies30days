//GFG Question: https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#

class Solution{
    public:
    
    vector<vector<int>> doublet(vector<int> &arr, int k, int beg, int n)
    {
        vector<vector<int>> ans;
        int left=beg;
        int right=n-1;
        while(left<right)
        {
            if(left!=beg && arr[left]==arr[left-1])
            {
                left++;
                continue;
            }
            
            int sum=arr[left]+arr[right];
            if(sum==k)
            {
                vector <int> tempAns;
                tempAns.push_back(arr[left]);
                tempAns.push_back(arr[right]);
                ans.push_back(tempAns);
                left++;
                right--;
            }
            else if(sum>k)
            {
                right--;
            }
            else left++;
        }
        return ans;
    }
    
    vector<vector<int>> triplet(vector<int> &arr, int k, int beg, int n)
    {
        vector<vector<int>> ans;
        for(int i=beg; i<=n-3; i++)
        {
            if(i>beg && arr[i-1]==arr[i])
            continue;
            
            vector<vector<int>> tempAns = doublet(arr, k-arr[i], i+1, n);
            for(int j=0; j<tempAns.size(); j++)
            {
                //add arr[i] at beginning of each doublet
                tempAns[j].insert(tempAns[j].begin(), arr[i]);
                ans.push_back(tempAns[j]);
            }
            
        }
        return ans;
    }
    
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> ans;
        
        if(arr.size()<4)
        return ans;
        
        sort(arr.begin(), arr.end());
        int n=arr.size();
        
        for(int i=0; i<=n-4; i++)
        {
            if(i>0 && arr[i-1]==arr[i])
            continue;
            
            vector<vector<int>> tempAns = triplet(arr, k-arr[i], i+1, n);
            for(int j=0; j<tempAns.size(); j++)
            {
                //add arr[i] at beginning of each triplet
                tempAns[j].insert(tempAns[j].begin(), arr[i]);
                ans.push_back(tempAns[j]);
            }
        } 
        return ans;
    }
};
