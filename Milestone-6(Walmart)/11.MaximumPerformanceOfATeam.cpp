//Leetcode Question: https://leetcode.com/problems/maximum-performance-of-a-team/
//1383. Maximum Performance of a Team

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long maxi=0, sum=0;
        vector<pair<int, int>>v;
        for(int i=0; i<n; i++)
            v.push_back({efficiency[i], speed[i]});
        sort(v.rbegin(), v.rend());
        priority_queue<int, vector<int>, greater<int> >pq;
        for(int i=0; i<v.size(); i++)
        {
            if(pq.size()==k)
            {
                sum-=pq.top();
                pq.pop();
            }
            pq.push(v[i].second);
            sum+=v[i].second;
            maxi=max(maxi, sum*v[i].first);
        }
        return maxi%1000000007;
        
    }
};
