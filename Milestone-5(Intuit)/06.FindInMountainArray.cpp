//Leetcode Question: https://leetcode.com/problems/find-in-mountain-array/
//1095. Find in Mountain Array

class Solution {
public:
    int BinarySearch(int target, MountainArray &mountainArr, int low, int high, bool decr)
    {
        while(low<=high)
        {
            int mid = (high-low)/2+low;
            int midVal = mountainArr.get(mid);
            
            if(midVal==target)
                return mid;
            
            if(decr==false)
            {
                if(target<midVal)
                high=mid-1;
                else low=mid+1;
            }
            
            else{
               //decreasing sequence
                if(target<midVal)
                    low=mid+1;
                else high=mid-1;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int low=0;
        int len = mountainArr.length();
        int high=len-1;
        //to find peak element:
        while(low<=high)
        {
            int mid=(high-low)/2+low;
            int midVal = mountainArr.get(mid);
        
            int leftVal;
            int rightVal;
            
            if(mid-1>=0)
                leftVal = mountainArr.get(mid-1);
            else {
                low = low+1;
                continue;
            }
            
            if(mid+1<len)
               rightVal = mountainArr.get(mid+1);
            else {
                high = high-1;
                continue;
            }
            
            if(leftVal<midVal && midVal>rightVal)
            {
                    int ans = BinarySearch(target, mountainArr, 0, mid-1, false);
                    if(ans!=-1)
                        return ans;
                    if(target==midVal)
                    return mid;
                    return BinarySearch(target, mountainArr, mid+1, len-1, true);
            }
            
            if(leftVal<midVal && midVal<rightVal)
                low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
};
