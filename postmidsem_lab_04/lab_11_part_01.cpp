#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;
using namespace std;
lli n,m;

bool check(vector<lli> v[],lli c[],lli j)
{
   c[j]=1;
   queue<lli> q;
   q.push(j);
   while(!q.empty())
   {
       lli u=q.front();
       q.pop();
       if(!v[u].empty())
       {
           for(lli i=0;i<v[u].size();i++)
           {
               if(c[v[u][i]]==-1)
               {
                   c[v[u][i]]=1-c[u];
                   q.push(v[u][i]);
               }
               else
               if(c[v[u][i]]==c[u])
               {
                   //cout<<i<<" "<<u<<endl;
                   return false;
               }
           }
       }
   }
       return true;
}

bool bipartite(vector<lli> v[])
{
    lli c[n+1];
    //cout<<n<<endl;
   for(lli i=1;i<=n;i++)
   c[i]=-1;
   for(lli i=1;i<=n;i++)
   {
       if(c[i]==-1)
       {
           if(check(v,c,i)==false)
           return false;
       }
   }
   //for(lli i=1;i<=n;i++)
   //cout<<c[i]<<" ";
   return true;
}

int main()
{
   lli x,y;
   cin>>n>>m;
   vector<lli> v[n+1];
   for(lli i=0;i<m;i++)
   {
       cin>>x>>y;
       v[x].push_back(y);
       v[y].push_back(x);
   }
   if(bipartite(v)==true)
   cout<<"YES it is a bipartite graph"<<endl;
   else
   cout<<"NOT a bipartite graph"<<endl;

}