//Question on Leetcode
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        
        if(str1.length()<=0 || str2.length()<=0)
        {
            return "";
        }
        
        if(str1.length()==1 && str2.length()==1)
        {
            if(str1[0]==str2[0])
            {
                string ans="";
                ans+=str1[0];
                return ans;
            }
            else return "";
        }
        if(str1.length()>=str2.length());
        else
        {
            string temp;
            temp=str1;
            str1=str2;
            str2=temp;
        }
        
        int i=0;
        int t=str2.length();
        while(i<str1.length())
        {
            if(str1[i]==str2[i%t]);    
                else return "";
            i++;
        }
        
        if(str1.length()%t==0)
            return str2;
        
        int m = str1.length();
        
        for(int i=t/2; i>=1; i--)
        {
            if(t%i==0 && m%i==0)
            {
                int num_repeat = t/i;
                string ans=str2.substr(0, i);
                string temp="";
                for(int i=0; i<num_repeat; i++)
                {
                    temp+=ans;
                }
                if(temp==str2)
                    return ans;
            }  
        }
        return "";
    }
};
