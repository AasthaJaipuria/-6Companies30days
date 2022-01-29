/* Question: Given two library versions of an executable: for example, “10.1.1.3” and “10.1.1.9” or “10” and “10.1”.
Find out which one is more recent? Strings can be empty also.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cout<<"Enter String 1: ";
    getline(cin, s1);
    cout<<"Enter String 2: ";
    getline(cin, s2);
    
    int len1 = s1.length();
    int len2 = s2.length();
    if(len1==0 || len2==0)
    {
        if(len1==0 && len2==0)
        {
            cout<<"Both are empty therefore equally recent.";
            return 0;
        }
        if(len1==0)
        {
            cout<<"String 1 is empty. String 2 is more recent.";
            return 0;
        }
        else{
            cout<<"String 2 is empty. String 1 is more recent.";
            return 0;
        }
    }
    
    int p1 = 0;
    int p2 = 0;
    int val1 = 0;
    int val2 = 0;
    while(p1<len1 && p2<len2)
    {
        while(p1<len1 && s1[p1]!='.')
        {
            val1=val1*10 + int(s1[p1]-'0');
            p1++;
        }
        
        while(p2<len2 && s2[p2]!='.')
        {
            val2 = val2*10 +int(s2[p2]-'0');
            p2++;
        }
        
        if(val1>val2)
        {
            cout<<"String 1 is more recent.";
            return 0;
        }
        else if(val2>val1)
        {
            cout<<"String 2 is more recent.";
            return 0;
        }
        else {
            p1++;
            p2++;
            val1=0;
            val2=0;
        }
    }
    if(p1<len1)
    {
        cout<<"String 1 is more recent.";
        return 0;
    }
    else if(p2<len2)
    {
        cout<<"String 2 is more recent.";
        return 0;
    }
    else cout<<"Both are equally recent.";
    return 0;
}
