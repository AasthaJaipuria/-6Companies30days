//Question on GFG: https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/
//Approach same as sliding window maximum

class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> ans;
        if(k>n)
        {
            ans.push_back(*max_element(arr.begin(), arr.end()));
            return ans;
        }
        int nge[n];
        stack<int> st;
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && arr[st.top()]<arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            nge[i]=n;
            
            else nge[i]=st.top();
            st.push(i);
        }
        
       /* for(int i=0; i<n; i++)
        cout<<nge[i]<<" ";
        cout<<endl;   */
        
        int j=0;
        for(int i=0; i<=n-k; i++)
        {
            if(nge[i]>i+k-1)
            ans.push_back(arr[i]);
            
            else{
                if(j<i)
                j=i;
                while(nge[j]<=i+k-1)
                j=nge[j];
                
                ans.push_back(arr[j]);
            }
            
        }   
        return ans;
    }
};
