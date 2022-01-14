//GFG Question: https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/

class Solution
{
    public:
    vector <string> mapping {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> func(int beg, int a[], int N)
    {
        vector<string> semiAns;
        if(N==0)
        {
            semiAns.push_back("");
            return semiAns;
        }
        
        int begChar=a[beg];
        semiAns = func(beg+1, a, N-1);
        
        vector<string> finalAns;
        
        for(int i=0; i<mapping[begChar].length(); i++)
        {
            for(int j=0; j<semiAns.size(); j++)
            {
                finalAns.push_back(mapping[begChar][i]+semiAns[j]);
            }
        }
        return finalAns;
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        return func(0, a, N);
    }
};
