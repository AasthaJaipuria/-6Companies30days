//GFG Question: https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1/#

//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/


int sumCount(Node* root, int X, int &count)
{
    int leftSum, rightSum;
    if(root->left)
    leftSum = sumCount(root->left, X, count);
    else leftSum=0;

    if(root->right)
    rightSum = sumCount(root->right, X, count);
    else rightSum=0;
    
    int sum=root->data + leftSum + rightSum;
    if(sum==X)
    count++;
    return sum;
}

//Function to count number of subtrees having sum equal to given sum.
int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int count=0;
	if(root==NULL)
	return X==0;
	if(root->left==NULL && root->right==NULL)
	return X==root->data;
	sumCount(root, X, count);
	return count;
}
