//Leetcode Question: https://leetcode.com/problems/number-of-boomerangs/
// 447. Number of Boomerangs

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        if(n<3)
            return 0;
        
        int count=0;
        
        for(int i=0; i<n; i++)
        {
            map <int, int> m;
            for(int j=0; j<n; j++)
            { 
                if(i==j)
                    continue;
                int dist = pow(points[i][0]-points[j][0], 2) + pow(points[i][1]-points[j][1], 2);
/*it is actually square of distance, but if square are equal, then +ve square root will also be equal */
                m[dist]++;
            }
          
            map<int, int>::iterator it = m.begin();
            while(it!=m.end())
            {
                if(it->second>=2)
                {
                    int p=it->second;
                    count=count+(p*(p-1));  //pick any 2, pC2, then arrange them 2!
                    cout<<p<<" "<<count<<"\n";
                }
                it++;
            }
        }
        return count;
    }
};
