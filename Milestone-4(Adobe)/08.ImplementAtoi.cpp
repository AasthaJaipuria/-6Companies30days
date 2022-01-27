//GFG Question: https://practice.geeksforgeeks.org/problems/implement-atoi/1/#

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int len = str.length();
        int ans=0;
        int factor = 1;
        for(int i=len-1; i>=0; i--)
        {
            if(str[i]>='0' && str[i]<='9')
            {
                int val = str[i]-'0';
                ans+=(val*factor);
                factor*=10;
            }
            else if(str[i]=='-' && i==0)
            {
                ans=-1*ans;
                return ans;
            }
            else return -1;
        }
        return ans;
    }
};
