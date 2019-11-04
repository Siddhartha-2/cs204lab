#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define mod 1000000007
#define mod1 998244353
#define lli long long int
#define plli pair<lli,lli>
#define REP(i,a,b) for(lli i=a;i<b;i++)
#define REPI(i,a,b) for(lli i=b-1;i>=a;i--)
#define F first
#define S second
#define PB push_back
#define DB pop_back
#define MP make_pair
#define MT make_tuple
#define G(a,b) get<a>(b)
typedef vector<plli> vii;
typedef vector<lli> vi;

vector<pair<lli,pair<lli,lli>>> edges;

class dsu{
  public:
      vector<lli> p,rank,setsize;
      lli numset;
      dsu(lli m)
      {
        numset=m;
        p.assign(m+1,0);
        for(lli i=0;i<=m;i++)
          p[i]=i;
        rank.assign(m+1,0);
        setsize.assign(m+1,1);
      }

      lli findSet(lli x)
      {
          return p[x]==x ? x : p[x]=findSet(p[x]);
      }

      bool isSameSet(lli x,lli y)
      {
          return findSet(x)==findSet(y);
      }

      void unionSet(lli x,lli y)
      {
           x=findSet(x);
           y=findSet(y);
          if(x!=y)
          {
              numset--;
              if(rank[x]>rank[y])
              {
                  p[y]=x;
                  setsize[x]+=setsize[y];
              }
              else
              {
                  p[x]=y;
                  setsize[y]+=setsize[x];
                  if(rank[x]==rank[y])
                  rank[y]+=1;
              } 
          }
      }

      lli numOfDisjointSet()
      {
          return numset;
      }

      lli sizeOfSet(lli x)
      {
          return setsize[findSet(x)];
      }
};

int main()
{
    lli n,m;
    cin>>n>>m;
    lli x,y,w;
    REP(i,0,m)
    {
     cin>>x>>y>>w;
     edges.PB({w,{x,y}});
    }
    sort(edges.begin(),edges.end(),greater<pair<lli,pair<lli,lli>>>());
    dsu uf(n+1);
    lli cost=1;
    for(auto i: edges)
    {
        if(!(uf.isSameSet(i.second.first,i.second.second)))
        {
            cost=( ((cost)%mod) * ((i.first)%mod) )%mod;
            uf.unionSet(i.second.first,i.second.second);
        }
    }
    cout<<cost<<endl;
}