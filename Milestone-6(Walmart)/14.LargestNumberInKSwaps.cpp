//GFG Question: https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1/

class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string ans = "";
    
    void func(string str, int k, int len, int idx)
    {
        if(str>ans)
        ans=str;
        
        if(k<=0)
        return;
        
        char maxVal=str[idx];
        for(int j=idx+1; j<len; j++)
        {
            if(str[j]>maxVal)
            maxVal=str[j];
        }
        
        if(maxVal!=str[idx])
        k--;
        
        for(int j=idx; j<len; j++)
        {
            if(str[j]==maxVal)
            {
                swap(str[j], str[idx]);
                func(str, k, len, idx+1);
                swap(str[j], str[idx]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       int len=str.length();
       int count=0;
       if(len<=1 || k<=0)
       return str;
       
       func(str, k, len, 0);
       return ans;
    }
    /*  Keep this in mind!!!
   input: 129814999 k=4
here if there is no recursion 
in 1 swap : 929814991
in 2 swap : 999814921
//now 9 has no elements bigger than that in later part
in 3 swap : 999914821
in 4 swap : 999984121
// 4 swaps completed completed so ur answer is 999984121 which is wrong.
actual answer is 999984211 
=>929814991
=>999814291// see here i didn't swap with last 9, i did it second last 9
=>999914281//
=>999984211
now we got best answer with same 4 swaps,
so for every index we have to try swapping it with all the next maximum numbers
because we don't know swapping with which maximum can give us right answer
    */
};
