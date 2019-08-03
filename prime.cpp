#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;
void isprime(ulli n)
{  
    int flag=0;
    for(ulli i=2;i*i<=n;i++)
    {
        if(n%i==0)
           {
               flag=1;
               break;
           }
    }
    if(flag==1)
    cout<<"NOT A PRIME NUMBER"<<endl;
    else
    cout<<"PRIME NUMBER"<<endl;
    
}
int main()
{
   ulli n;
   cin>>n;
   isprime(n);
}