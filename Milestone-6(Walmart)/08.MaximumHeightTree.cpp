//GFG Question: https://practice.geeksforgeeks.org/problems/maximum-height-tree4803/1/?page=2&company[]=Walmart&query=page2company[]Walmart

class Solution{
public:
    int height(int N){
        // code here
        
        //sum of first n nos is n(n+1)/2
        //to get n, linear eqn will become n^2+n-2*Sum=0
        //Use discriminant method
        //by substituting all the values, we get value of n as below;
        return (-1+sqrt(1+8*N))/2;
    }
};
