#include <bits/stdc++.h>
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long double ldb;
using namespace std;

class Node 
{
 public:
  lli user_id;
   lli value;
    Node *left; 
    Node *right;
     int height; 
};

Node* newNode(lli user_id,lli value)  
{  
    Node* node = new Node(); 
    node->user_id = user_id;  
    node->value=value;
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1;  
    return(node);  
}
lli height(Node* N)
{
 if(N==nullptr)
  return 0; 
  return N->height;
}

lli max(lli a,lli b){ 
  return (a>b)?a:b;
}

Node *rightRotate(Node *y) {
 Node *x = y->left;
  Node *T2 = x->right;
   x->right = y;
    y->left = T2; 
    y->height = max(height(y->left),height(y->right)) + 1;
     x->height = max(height(x->left),height(x->right)) + 1;
      return x; 
} 

Node* leftRotate(Node* x){ 
  Node* y=x->right; 
  Node* T2=y->left;
 y->left=x; 
 x->right=T2;
 x->height=max(height(x->left),height(x->right))+1;
  y->height=max(height(y->left),height(y->right))+1;
  return y;
}

lli getBalance(Node *N){ 
  if(N==nullptr) return 0;
   return height(N->left)-height(N->right);
}

Node* insert(Node* node,lli user_id,lli value){
  if(node==nullptr)
   return newNode(user_id,value);
    if(user_id<node->user_id) 
      node->left=insert(node->left,user_id,value);
       else 
      if(user_id>node->user_id)
      node->right=insert(node->right,user_id,value); 
    else
     {
      return node;
       }
 lli balance = getBalance(node);
 if(balance>1 && user_id<node->left->user_id)
   return leftRotate(node);

  if (balance < -1 && user_id > node->right->user_id)  
        return leftRotate(node);  

    if (balance > 1 && user_id> node->left->user_id)  
    {  
        node->left = leftRotate(node->left);  
        return rightRotate(node);  
    }  
  
    if (balance < -1 && user_id < node->right->user_id)  
    {  
        node->right = rightRotate(node->right);  
        return leftRotate(node);  
    }  
  
    return node;     
}

void preOrder(Node *root)  
{  
    if(root != NULL)  
    {  
        cout << root->user_id << " "<<root->value<<endl;  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
} 

Node* search(Node* node, lli user_id)
{
  if(node==nullptr)
    return nullptr;
    //cout<<"hh"<<endl;
  while(node!=nullptr)
  {
    if(user_id==node->user_id)
      return node;
    if(user_id<node->user_id)
      node=node->left;
    else
      node=node->right;
  }
  return nullptr;
} 

int main()
{
  lli n,t,p,user_id,value,c=0,m=0,ans=0;
  cin>>n>>t;
  Node* root=nullptr;
  while(t--)
  {
    cin>>p;
    if(p==1)
    {
      c=1;
      cin>>user_id>>value;
      Node* temp=search(root,user_id);
      if(temp==nullptr)
      { 
        //cout<<"jj"<<endl;
        root =insert(root,user_id,value);
        if(value>m)
        {
          m=value;
          ans=user_id;
        }
      }
      else
      {
      //  cout<<"ll"<<endl;
        //cout<<temp->value<<" "<<value<<endl;
        temp->value=(temp->value)+value;
        //cout<<temp->user_id<<endl;
        if(temp->value>m)
        {
          m=temp->value;
          ans=temp->user_id;
        }
      }
    }
    else
    {
      if(c==0)
      {
        cout<<"DATA NOT AVAILABLE"<<endl;
        continue;
      }
      cout<<ans<<endl;
    }
  }
  //preOrder(root);
  return 0;
}