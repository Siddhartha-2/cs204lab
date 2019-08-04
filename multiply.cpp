#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{  int t;
 cin>>t;
 while(t--)
    {
        string a,b;
    cin>>a>>b;
    lli k=0,kk=0,s=0,c=0;
    lli ans[a.length()+b.length()]={0};
    if(a=="0"||b=="0")
    {
      cout<<0<<endl;
      return 0;
    }
    for(lli i=b.length()-1;i>=0;i--)
    {  
        kk=0;
        c=0;
        for(lli j=a.length()-1;j>=0;j--)
        {
            s=(a[j]-'0')*(b[i]-'0')+ans[k+kk]+c;
            c=s/10;
            s%=10;
            ans[k+kk]=s;
            kk++;
        }
        if(c>0)
        { 
         ans[k+kk]+=c;
         kk++;
        }

        k++;
    }
    lli j=a.length()+b.length()-1;
    while(j>=0&&ans[j]==0)
    j--;
    if(j==-1)
    {
        cout<<'0'<<endl;
        return 0;
    }
    for(lli i=j;i>=0;i--)
    {
        string cc=to_string(ans[i]);
        //char cc=ans[i]+48;
        cout<<cc;
    }
    cout<<endl;
    }
}