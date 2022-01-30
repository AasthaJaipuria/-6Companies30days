//Leetcode Question: https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
//1536. Minimum Swaps to Arrange a Binary Grid

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> TrailingZeroCount;
        for(int i=0; i<n; i++)
        {
            int count=0;
            int j=n-1;
            while(j>=0 &&  grid[i][j]==0)
            {
                count++;
                j--;
            }
            TrailingZeroCount.push_back(count);
        }
        
        int ans=0;
        
        for(int i=0; i<n; i++)
        {
            int TargetZeros = n-i-1;
            if(TrailingZeroCount[i]>=TargetZeros)
                continue;
            else{
                int j=i+1;
                while(j<n && TrailingZeroCount[j]<TargetZeros)
                    j++;
                if(j<n && TrailingZeroCount[j]>=TargetZeros)
                {
                   ans+=(j-i); 
                    int row = TrailingZeroCount[j];
                    TrailingZeroCount.erase(TrailingZeroCount.begin()+j);
                    TrailingZeroCount.insert(TrailingZeroCount.begin()+i, row);
                }
                else return -1;
            }
        }
        return ans;
    }
};
