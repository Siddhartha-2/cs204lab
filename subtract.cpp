#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    string temp;                            // to swap the strings
    int d=0,i=0;
    if(a.length()<b.length())              // to make sure string a is bigger than string b
    {
       temp=a;                             // to swap the strings
       a=b;
       b=temp;
    }
    if(a.length()==b.length())
    {
        while(1)
        {
            if(a[i]>b[i])
            {
                break;
            }
            else
            if(a[i]<b[i])
            {
                temp=a;
                b=a;
                a=b;
                break;
            }
            i++;
            if(i==a.length())              // if both strings equal break the loop
            {
                d=1;
                break;
            }
            
        }
    }
    if(d==1)                
    {  
        cout<<'0'<<endl;
        return 0;
    }
    string ans="";
    int s=0,c=0,ka=a.length()-1,kb=b.length()-1;      // variable c to store carry
    while(ka>=0||kb>=0)                               // string a is bigger than string b so ka >= kb so kb first become zero
    {
        if(ka>=0&&kb>=0)
        {
            s=(a[ka--]-'0')-(b[kb--]-'0')-c;
        }
        else
        if(ka>=0)
        {
            s=(a[ka--]-'0')-c;
        }
        if(s<0)
        {
            s+=10;
            c=1;
        }
        else
           c=0;
        char cc= s+48;                                // to convert integer to character
        ans = cc+ans;
    }
    cout<<ans<<endl;
}