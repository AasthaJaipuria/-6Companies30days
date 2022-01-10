//GFG Question: https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/

class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans="";
        while(n>0)
        {
            int lastchar=(n-1)%26;
            //if not n-1, then 1 % 26, would have meant 1, 
            //26%26, Z would be 0; that's why we have initialized with 'A'+0
            //so that z would be 'A'+25;
            //n-1 is used
            ans=char('A'+lastchar) +ans;
            n=(n-1)/26; //z is 26, 26/26 is 1, but it is not double character string.
            //all have offset of 1, therefore, we have taken(n-1);
        }
        return ans;
    }
};
