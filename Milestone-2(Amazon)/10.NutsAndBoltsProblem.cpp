//GFG Problem: https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1#

class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
	   // char arr[] = {'!', '#', '$', '%', '&', '*', '@', '^', '~'};:This arr is
	   //sorted in ascending order(in terms of ascii values)
	   
	   sort(nuts, nuts+n);
	   sort(bolts, bolts+n);
	}

};
