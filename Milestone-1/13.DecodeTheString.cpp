//Question is on GFG: https://practice.geeksforgeeks.org/problems/decode-the-string2444/1#

class Solution{
public:
    string decodedString(string s){
        // code here
        stack <string> st;
        int t=s.size();
        
        for(int i=0; i<t; i++)
        {
            if(s[i]!=']')
            {
                string temp="";
                temp+=s[i];
                st.push(temp);
            }
            else 
            {
                string temp="";
                while(st.top()!="[")
                {
                    temp=st.top()+temp;
                    st.pop();
                }
                st.pop();
                //to calculate count
                int count=0;
                int place=1;
                
                if(st.top()[0]>='0' && st.top()[0]<='9')
                {
                    while(!st.empty() && (st.top()[0]>='0' && st.top()[0]<='9'))
                    {
                    count=count+(int(st.top()[0]-'0')*place);
                    place*=10;
                    st.pop();
                    }
                }
                else count=1;
               
                string temp2="";
                for(int j=0; j<count; j++)
                temp2+=temp;
                st.push(temp2);
            }
        }
        return st.top();
    }
};
