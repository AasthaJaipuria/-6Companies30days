//Leetcode Question: https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
// 2038. Remove Colored Pieces if Both Neighbors are the Same Color

class Solution {
public:
    bool winnerOfGame(string colors) {
        
        int len = colors.length();
        if(len<3)
            return false;
        int count=1;
        int countA=0;
        int countB=0;
        
        for(int i=1; i<len; i++)
        {
            if(colors[i]==colors[i-1])
                count++;
            else
            {
                if(colors[i-1]=='A' && count>=3)
                    countA+=(count-2);
                else if(colors[i-1]=='B' && count>=3)
                    countB+=(count-2);
                
                count=1;
            }
        }
        
        if(count>=3)
        {
            if(colors[len-1]=='A')
                countA+=(count-2);
            else if(colors[len-1]=='B')
                countB+=(count-2);
        }
        
        return countA>countB;
    }
};
