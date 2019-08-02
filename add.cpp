#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int c=0,ka=a.length()-1,kb=b.length()-1,s=0;  // c is for carry initially it is 0
    string ans="";                               // variable ans to store the answer
    while(ka>=0||kb>=0)
    {
        if(ka>=0&&kb>=0)
          s=c+(a[ka--]-'0')+(b[kb--]-'0');        // variable s to store the sum of two digits
        else
        if(ka>=0)
          s=c+(a[ka--]-'0');
        else
        if(kb>=0)
          s=c+(b[kb--]-'0');
        c=s/10;
        s%=10;
        char cc=s+48;                           // to convert integer to character we add 48
        ans=cc+ans;  
    }
    if(c>0)                                     // if carry is positive then add it
     { 
         char cc=c+48;
         ans=cc+ans;
     }
     cout<<ans<<endl;
}