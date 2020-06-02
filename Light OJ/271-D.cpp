#include<bits/stdc++.h>
using namespace std;

int c[1509];
unsigned long long p[1509];
set<unsigned long long>st;
int main()
{
    //p[0]=1;
    //for(int i=1; i<1509; i++) p[i]=p[i-1]*37;
    string s,v;
    int k;
    cin>>s>>v>>k;
    int l=s.size();
    for(int i=0; i<l; i++)
    {
        c[i+1]=v[s[i]-'a']-'0';
        if(c[i+1]==0) c[i+1]=1;
        else c[i+1]=0;

    }
    for(int i=2; i<=l; i++) c[i]+=c[i-1];
    for(int i=1; i<=l; i++)
    {
        unsigned long long h=0,u=1;
        for(int j=i; j<=l; j++)
        {
            if(c[j]-c[i-1]<=k)
            {
               // string ss;
               // ss=s.substr(i-1,j-i+1);
               // cout<<ss<<endl;
                h+=u*s[j-1];
                u*=53;
                //cout<<h<<endl;
                st.insert(h);
            }
            else break;
        }
    }
    cout<<st.size()<<endl;
    //for(int i=0;i<l;i++) cout<<c[i]<<" ";
}
