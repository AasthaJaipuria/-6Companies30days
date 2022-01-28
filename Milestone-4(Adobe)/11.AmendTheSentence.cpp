//GFG Question: https://practice.geeksforgeeks.org/problems/amend-the-sentence3235/1#

class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        s[0] = towlower(s[0]);
        
        int i=1;
        while(i<s.length())
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                s.insert(i, " ");
                i++;
                s[i]=towlower(s[i]);
            }
            i++;
        }
        return s;
    }
};
