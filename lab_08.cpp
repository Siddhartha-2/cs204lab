#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ll finddist(ll x, ll y)
{
  return (x*x+y*y);
}

void insertionSort(ll arr[], ll n)  
{  
    ll i, key, j;  
    for (i=1;i<n;i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  

ll findmedian(ll arr[], int n)
{
  insertionSort(arr, n);
  return(arr[n/2]);
}

void swap(ll *a, ll *b)
{
  ll t;
  t=*a;
  *a=*b;
  *b=t;
}

ll partition(ll arr[],ll l,ll r,ll x)
{
  ll i;
  for(i=l;i<r;i++)
  {
    if(arr[i]==x)
      break;
  }
  swap(&arr[i],&arr[r]);
    i=l;
  for(ll j=l;j<=r-1;j++)
  {
       if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i;
  

}

ll radius(ll arr[], ll l,ll r,ll k)
{
  ll n=r-l+1;
  
  ll i,median[(n+4)/5];
  for(i=0;i<n/5;i++)
  {
    median[i]=findmedian(arr+l+i*5,5);
  }
  if(i*5<n)
  {
    median[i]=findmedian(arr+l+i*5,n%5);
    i++;
  }

  ll medOfmed= (i == 1)? median[i-1]: 
                                 radius(median, 0, i-1, i/2); 
  
        
        ll position = partition(arr, l, r, medOfmed); 
  
      
        if (position-l == k-1) 
            return arr[position]; 
        if (position-l > k-1)  
            return radius(arr, l, position-1, k); 
  
        
        return radius(arr, position+1, r, k-position+l-1);
}



int main()
{
  ll n,p;

  cin>>n;
  
  for(int j=0;j<n;j++)
  {
    cin>>p;
    ll ar[p];
    {
      for(int m=0;m<p;m++)
      {
        ll x,y;
        cin>>x>>y;
        ar[m]=finddist(x,y);
      }
    }
    if(p%2==0)
    cout<<sqrt(radius(ar,0,p-1,(p/2)))<<endl;
    else cout<<sqrt(radius(ar,0,p-1,(p/2)+1))<<endl;
  }
  return 0;
}