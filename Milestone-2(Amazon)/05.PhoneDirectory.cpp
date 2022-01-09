//Question on GFG: https://practice.geeksforgeeks.org/problems/phone-directory4628/1/#

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>> ans(s.length());
        sort(contact, contact+n);
        
        vector<string> contacts;
        
        for(int i=0; i<n; i++)
        contacts.push_back(contact[i]);
        
        int temp=1;
        while(temp<contacts.size())
        {
            if(contacts[temp]==contacts[temp-1])
            {
                contacts.erase(contacts.begin()+temp);
            }
            else temp++;
        }
    
        for(int i=0; i<s.length(); i++)
        {
            for(int j=0; j<contacts.size(); j++)
            {
                if(contacts[j].length()>i && contacts[j][i]==s[i])
                ans[i].push_back(contacts[j]);
                else {
                    contacts.erase(contacts.begin()+j);
                    j--;
                }
            }
            if(contacts.size()<=0)
            {
                ans[i].push_back("0");
                i++;
                while(i<s.length())
                {
                    ans[i].push_back("0");
                    i++;
                }
            }
        }           
       return ans;
    }
};
