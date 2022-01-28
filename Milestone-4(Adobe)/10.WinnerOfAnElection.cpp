//GFG Question: https://practice.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1/#

class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        map <string, int> m;
        for(int i=0; i<n; i++)
        m[arr[i]]++;
        
        int maxVotes = 0;
        map<string, int> :: iterator it = m.begin();
        map<string, int> :: iterator maxVoteIt = m.begin();
        while(it!=m.end())
        {
            if(it->second>maxVotes)
            {
                maxVotes = it->second;
                maxVoteIt = it;
            }
            it++;
        }
        vector<string> v;
        v.push_back(maxVoteIt->first);
        v.push_back(to_string(maxVotes));
        return v;
    }
};
