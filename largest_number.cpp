#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;
using namespace std;

void swap(string* a, string* b)  
{  
    string t = *a;  
    *a = *b;  
    *b = t;  
}  
  
 bool compare(string a,string b)
 {
     string x=a.append(b);
     string y=b.append(a);
     for(lli i=0;i<y.length();i++)
     {  
         if(x[i]==y[i])
         continue;
         if(x[i]>y[i])
         return true;
         else
         return false;
     }
     return false;
 }

int partition (string arr[], lli low, lli high)  
{  
    string pivot = arr[high];
    lli i = (low - 1); 
  
    for (lli j = low; j <= high - 1; j++)  
    {
        if (compare(arr[j],pivot))  
        {  
            i++; 
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  

void quickSort(string arr[], lli low, lli high)  
{  
    if (low < high)  
    {  
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        lli n;
        cin>>n;
        string s[n];
        for(lli i=0;i<n;i++)
        {
            cin>>s[i];
        }
        //sort(s,s+n,compare);
        quickSort(s,0,n-1);
        for(lli i=0;i<n;i++)
        cout<<s[i];
        cout<<endl;
    }
}