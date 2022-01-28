//GFG Question: https://practice.geeksforgeeks.org/problems/next-higher-palindromic-number-using-the-same-set-of-digits5859/1/#

class Solution{
  public:
    string nextPalin(string N) { 
        //complete the function here
        
        //first of all check whether the string is already palindromic
        int len = N.length();
        if(len<=3)
        return "-1";
       
        int mid = len/2-1;
        int i=mid-1;
        while(i>=0 && N[i]>=N[i+1])
        i--;
        if(i>=0)
        {
            int j=mid;
            while(j>=0 && N[j]<=N[i])
            j--;
            swap(N[i], N[j]);
            swap(N[len-1-i], N[len-1-j]);
        
            int k=i+1;
            int l = mid;
            while(k<l)
            {
                swap(N[k], N[l]);
                swap(N[len-1-k], N[len-1-l]);
                k++; l--;
            }
            return N;
        }
        else return "-1";
    }
};
