class Solution{
  public:
  bool isAnagram(string s1, string s2)
{
    if(s1.length()!=s2.length())
    return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if(s1==s2)
    return true;
    return false;
}

    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string> > ans;
        if(string_list.size()<=0)
        return ans;
        if(string_list.size()==1)
        {
            vector<string> temp;
            temp.push_back(string_list[0]);
            ans.push_back(temp);
            return ans;
        }
        
        vector<string> temp;
            temp.push_back(string_list[0]);
            ans.push_back(temp);
        
        for(int i=1; i<string_list.size(); i++)
        {
            int group=0;
            while(group<ans.size() && !isAnagram(string_list[i], ans[group][0]))
            {
                group++;
            }
            if(group<ans.size())
            {
                ans[group].push_back(string_list[i]);
                vector<string> temp;
                temp = ans[group];
                ans.erase(ans.begin() + group);
                ans.push_back(temp);
            }
            else 
            {
                vector<string> temp;
            temp.push_back(string_list[i]);
            ans.push_back(temp);
            }
        }
        return ans;
    }
};
