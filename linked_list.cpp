#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;
using namespace std;

struct Node{
    tuple<int,int> point;
    struct Node *p;
};
struct Node* head;

void AddFirst(int x,int y)
{
    struct Node* temp= head;
    struct Node* temp1=(struct Node*)malloc(sizeof(struct Node));
    
    get<0>(temp1->point)=x;
    get<1>(temp1->point)=y;
    temp1->p=temp;
    head=temp1;
    return;
}
int DelFirst()
{
    if(head==NULL)
        return -1;
    struct Node* temp=head;
    struct Node* temp1=head->p;
    head=temp1;
    free(temp);
    return 0;
}

int Del(int x,int y)
{
    if(head==NULL)
        return -1;
    struct Node* temp=head;
    struct Node* prev=NULL;
    struct Node* p=NULL;
    while(temp!=NULL)
    {
        if(get<0>(temp->point)==x&&get<1>(temp->point)==y)
        {
          p=temp;
          break;
        }
        prev=temp;
        temp=temp->p;
    }
    if(p==NULL)
        return -1;
    if(prev==NULL)
    {
        head=temp->p;
        free(temp);
        return 0;
    }
    else
    {
        prev->p=temp->p;
        free(temp);
        return 0;
    }
}

int Search(float d)
{
    if(head==NULL)
        return 0;
        int s=0;
    struct Node* temp=head;
    while(temp!=NULL)
    {
        int dd=(get<0>(temp->point))*(get<0>(temp->point))+(get<1>(temp->point))*(get<1>(temp->point));
        if(dd<=d*d)
        {
            cout<<'('<<get<0>(temp->point)<<','<<get<1>(temp->point)<<')'<<" ";
            s=1;
        }
        temp=temp->p;
    }
    cout<<endl;
    if(s==0)
    return 0;
    return 1;
}
int Search(int x,int y)
{  
  int c=0;
    if(head==NULL)
        return 0;
    struct Node* temp=head;
    while(temp!=NULL)
    {
        if(get<0>(temp->point)==x&&get<1>(temp->point)==y)
            c++;
        temp=temp->p;
    }
    return c;
}

int length()
{ 
    int l=0;
    struct Node* temp=head;
    while(temp!=NULL)
    {
        l++;
        temp=temp->p;
    }
    return l; 
}
int main()
{
   head=NULL;
   int t,x,y,p;
   float d;
   cin>>t;
   while(t--)
   {
    cin>>p;
    if(p==1)
    {
        cin>>x>>y;
        AddFirst(x,y);
    }
    if(p==2)
    {
        int xx=DelFirst();
        if(xx==-1)
        cout<<-1<<endl;
    }
    if(p==3)
    { 
        cin>>x>>y;
        cout<<Del(x,y)<<endl;
    }
    if(p==4)
    {
        cin>>d;
        int xx=Search(d);
        if(xx==0)
        cout<<0<<endl;
    }
    if(p==5)
    {
        cin>>x>>y;
        cout<<Search(x,y)<<endl;
    }
    if(p==6)
    {
        cout<<length()<<endl;
    }
   }
}