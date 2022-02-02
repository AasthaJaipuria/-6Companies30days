//GFG Question: https://practice.geeksforgeeks.org/problems/find-the-missing-no-in-string/1/#

/* You are required to complete this function
which return the required missing number
if present else return -1*/

int makeNo(const string& str, int len, int i, int m)
{
    if(i+m>len)
    return -1;
    
    int val=0;
    int j=i;
    for(int k=0; k<m; k++)
    {
        val=val*10 + (str[j]-'0');
        j++;
    }
    return val;
}
int missingNumber(const string& str)
{
    // Code here
    int len = str.length();
    if(len<2)
    return -1;
    
    //Start from word length 1 and continue till 6 until ans is found
    
    for(int i=1; i<=6; i++)
    {
        //first of all make the first number.
        int n = makeNo(str, len, 0, i);
        if(n==-1)
        return -1;
        
        int missingNo = -1;
        bool fail=false;
        for(int j=i; j<len; j+=(1+int(log10(n))))
        {
            if(missingNo==-1 && makeNo(str, len, j, 1+int(log10(n+2)))==n+2)
            {
                missingNo = n+1;
                n=n+2;
            }
            
            else if(makeNo(str, len, j, 1+int(log10(n+1)))==n+1)
              {
                  n=n+1;
              }
    
            else 
            {
                fail=true;
                break;
            }
        }
        if(fail==false && missingNo!=-1)
        return missingNo;
    }
    return -1;
}
