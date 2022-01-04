//Question is on GFG https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/#

class Solution {
	public:
		int CountWays(string str){
		    // Code here
		    if(str.length()<=0)
		    return 0;
		    
		    if(str.length()==1)
		    {
		        if(str[0]>='1' && str[0]<='9')
		        return 1;
		        else return 0;
		    }
		    
		    if(str[0]=='0')
		    return 0;
		    
		    int len=str.size();
		    int dp[len];
		    
		    dp[0]=1;
		    
		    for(int i=1; i<len; i++)
		    {
		        if(str[i]!='0')
		        {
		            if(str[i-1]=='1')
		            {
		                dp[i]=dp[i-1];
		                if(i-2>=0)
		                dp[i]=(dp[i]+dp[i-2])%1000000007;
		                else dp[i]=(dp[i]+1)%1000000007;
		            }
		            else if(str[i-1]=='2')
		            {
		                dp[i]=dp[i-1];
		                if(str[i]<='6')
		                {
		                    if(i-2>=0)
		                    dp[i]=(dp[i]+dp[i-2])%1000000007;
		                    else dp[i]=(dp[i]+1)%1000000007;
		                }
		            }
		            else dp[i]=dp[i-1];
		        }
		        else if(str[i]=='0')
		        {
		            if(str[i-1]=='1' || str[i-1]=='2')
		            {
		                if(i-2>=0)
		                dp[i]=dp[i-2];
		                else dp[i]=1;
		            }
		            else return 0;
		        }
		    }
            return dp[len-1];
		}
};
