//Question is available on GFG https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1#

class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        if(S.length()<=0 || S.length()>8)
        return "";
        
        int t=S.length();
        
        string ans;
        int num=1;
        stack <char> s;
        for(int i=0; i<t; i++)
        {
            if(S[i]=='D')
            {
                s.push(char(num)+'0');
                num++;
            }
            else if(S[i]=='I')
            {
                s.push(char(num)+'0');
                num++;
                while(!s.empty())
                {
                    ans+=s.top();
                    s.pop();
                }
            }
        }
        s.push(char(num)+'0');
        while(!s.empty())
        {
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};
