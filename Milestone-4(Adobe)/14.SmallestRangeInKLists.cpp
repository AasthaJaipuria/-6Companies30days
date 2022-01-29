//GFG Question: https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1/#

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
          //code here
          priority_queue <pair<int, int>, vector<pair<int, int>>, greater <pair<int, int>>>  pq;
          int pointers[k];
          int maxi=INT_MIN;
          for(int i=0;i<k; i++)
          {
              pq.push(make_pair(KSortedArray[i][0], i));
              maxi=KSortedArray[i][0]>maxi?KSortedArray[i][0]:maxi;
              pointers[i]=0;
          }
          int mini = pq.top().first;
          int rangeMin = maxi-mini;
          pair<int, int> ans = make_pair(mini, maxi);
          
          while(pointers[pq.top().second]+1<n)
          {
              int row = pq.top().second;
              int col = pointers[pq.top().second]+1; //the next index to mini
              int val = KSortedArray[row][col];
              pointers[row]++;
              if(val>maxi)
              maxi = val;
             pq.pop();
             pq.push(make_pair(val, row));
             mini = pq.top().first;
             int range = maxi-mini;
             if(range<rangeMin)
             {
                 rangeMin = range;
                 ans = make_pair(mini, maxi);
             }
          }
          return ans;
    }
};
