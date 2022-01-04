//Find the kid who gets the damaged toy

/*  In a circle children are sitting (ordered. By ascending id) 
there is a random number D(1 to N) starting with D, 
distribute the toy to each sequential kid, until all toys distributed.
but the last toy is damaged, the task is to find the number at which 
kid is sitting who get the damage toy */

/* Total number of kids=N; Mth toy is damaged; Distribution is starting from D */

#include <bits/stdc++.h>
using namespace std;

int func(int N, int D, int M)
{
    if(M<=N-D+1) 
    return D+M-1;
    
    //first distribute N-D+1 toys, then start from beginning
    M=M-(N-D+1);
    if(M%N==0)
    return N;
    else return M%N;
}

int main()
{
    int N, D, M;
    cin>>N>>D>>M;
    cout<<func(N,D, M);
    return 0;
}
