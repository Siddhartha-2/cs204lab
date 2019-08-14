#include <bits/stdc++.h>
using namespace std;
void check(string exp)
{
    stack<char> s;
    for(long long int i=0;i<exp.length();i++)
    {
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='['||exp[i]=='<')
            {
                s.push(exp[i]);
                continue;
            }
            if(exp[i]=='|')
            {
                if(!s.empty()&&s.top()=='|')
                {
                    s.pop();
                }
                else
                {
                    s.push(exp[i]);
                }
                
                continue;
            }
            if(s.empty())
            {
                cout<<"NO"<<endl;
                return ;
            }
            char x=s.top();
            s.pop();
            int d=0;
            switch(exp[i])
            {
            case ')':
                if(x!='(')
                {
                    d=1;
                }
                break;
            case '}':
                if(x!='{')
                    d=1;
                break;
            case ']':
                if(x!='[')
                    d=1;
                break;
            case '>':
                if(x!='<')
                    d=1;
                
            }
            if(d==1)
            {
                cout<<"NO"<<endl;
                return ;
            }
            }
            if(!s.empty())
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
                return ;
}
int main()
{
    long long int t;
    cin>>t;
    string exp;
    while(t--)
    {
        cin>>exp;
        check(exp);
    }
    return 0;
}