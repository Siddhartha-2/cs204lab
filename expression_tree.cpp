#include <bits/stdc++.h>
using namespace std;

struct et 
{ 
    string value; 
    et* left, *right; 
};

et* newNode(string v) 
{ 
    et *temp = new et; 
    temp->left =NULL;
    temp->right = NULL; 
    temp->value = v; 
    return temp; 
};

int prec(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
bool operators(string s)
{
    if(s=="+"||s=="-"||s=="*"||s=="/"||s=="^")
    return true;
    return false;
}

int infixtopostfix(string s,string aa[])
{  
   string a="";
   stack<char> st;
   int k=0;
   for(int i=0;i<s.length();i++)
   {
    if(s[i]>='0'&&s[i]<='9')
    {
        a=s[i]+a;
    }
    else
    {
        if(a!="")
        { 
            aa[k++]=a;
            a="";
        }
        if(s[i]=='(')
        st.push(s[i]);
        else
        if(s[i]==')')
        {
            while(!st.empty() && st.top() != '(') 
            { 
                char c = st.top(); 
                st.pop(); 
               aa[k++]=c;
            } 
            if(st.top() == '(') 
            { 
                char c = st.top(); 
                st.pop(); 
            } 
        }
        else
        
        {
            while(!st.empty() && (prec(s[i]) < prec(st.top())||(prec(s[i])==prec(st.top())&&prec(s[i])!=3)) )
            {   
                char c = st.top(); 
                st.pop(); 
                aa[k++]= c; 
            } 
            st.push(s[i]);
        }
    }
   }
   if(a!="")
   aa[k++]=a;
   while(!st.empty()) 
    { 
        char c = st.top(); 
        st.pop(); 
        aa[k++]= c; 
    } 
    for(int i=0;i<k;i++)
    cout<<aa[i]<<" ";
    cout<<endl;
    return k;
}

   et* constructTree(string postfix[],int k) 
{ 
    stack<et *> st; 
    et *t, *t1, *t2; 
  
    
    for (int i=0; i<k; i++) 
    { 
        
        if (!operators(postfix[i])) 
        { 
            t = newNode(postfix[i]); 
            st.push(t); 
        } 
        else 
        { 
            t = newNode(postfix[i]); 
  
            
            t1 = st.top(); 
            st.pop();      
            t2 = st.top(); 
            st.pop(); 
  
            t->right = t1; 
            t->left = t2; 
  
            st.push(t); 
        } 
    } 
    t = st.top(); 
    st.pop(); 
  
    return t; 
} 

int toInt(string s)  
{  
    int num = 0;   
    if(s[0]!='-') 
        for (int i=0; i<s.length(); i++)  
            num = num*10 + (int(s[i])-48);   
    else
        for (int i=1; i<s.length(); i++)  
        { 
            num = num*10 + (int(s[i])-48);  
            num = num*-1; 
        } 
      
    return num;  
}  
  
long long int  eval(et* root)  
{  
    if (root==NULL)  
        return 0;   
    if (!root->left && !root->right)  
        return toInt(root->value);  
  
    
    long long int l_val = eval(root->left);  
  
    
    long long int r_val = eval(root->right);  
    if (root->value=="+")  
        return l_val+r_val;  
  
    if (root->value=="-")  
        return l_val-r_val;  
  
    if (root->value=="*")  
        return l_val*r_val;  

    if(root->value=="/")
     return l_val/r_val;
    long long int s=1;
     for(int i=1;i<=r_val;i++)
     {
         s*=l_val;
     } 
     return s;
}  
int main()
{
    long long int t;
    cin>>t;
    string exp;
    while(t--)
    {
        cin>>exp;
        string aa[exp.length()];
        int k= infixtopostfix(exp,aa);
        et* t=constructTree(aa,k);
     // cout<<(t->left)->value<<" "<<(t->right)->value<<" "<<t->value<<endl;
       cout<<eval(t)<<endl;
    }
    return 0;
}