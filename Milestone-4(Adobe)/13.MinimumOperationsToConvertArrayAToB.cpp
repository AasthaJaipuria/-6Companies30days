//GFG Question: https://practice.geeksforgeeks.org/problems/minimum-insertions-to-make-two-arrays-equal/1/#

class Solution {
  public:
  
    bool BinSearch(int val, int start, int end, int B[])
    {
        while(start<=end)
        {
            int mid = (end-start)/2+start;
            if(B[mid]==val)
            return true;
            else if(val<B[mid])
            end=mid-1;
            else start=mid+1;
        }
        return false;
    }
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        
        //delete the extra elements
        int ans = 0;
        vector<int> v;
        for(int i=0; i<N; i++)  //O(NlogN)
        {
            if(BinSearch(A[i], 0, M-1, B))
                v.push_back(A[i]);
            else ans++; //these elements will be deleted
        }
        
    //We will make longest increasing subsequence(lis) of vector v;
    
    vector<int> lis;
    for(int i=0; i<v.size(); i++)
    {
        if(lis.size()==0)
        lis.push_back(v[i]);
        else if(v[i]>lis.back())
        lis.push_back(v[i]);
        else
        {
            int idx = lower_bound(lis.begin(), lis.end(), v[i])-lis.begin();
            lis[idx] = v[i];
        }
    }
     
   //lis.size() -> this is the size of longest increasing subsequence
    ans+=(M-lis.size()); //these are the elements not present in lis and have to be inserted
    ans+=(v.size()-lis.size()); //these are the elements which are to be deleted to form lis
    return ans;
    }
};
