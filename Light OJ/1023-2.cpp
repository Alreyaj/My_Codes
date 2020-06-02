#include<bits/stdc++.h>
using namespace std;

int c;
string s;
void dp(int i,string ans,int n,int cn)
{
    if(c>=cn) return;
    if(i==n-1)
    {
        cout<<ans<<endl;
        c++;
        return;
    }
    for(int j=i;j<n;j++)
    {
        string ss=ans;
        swap(ss[j],ss[i]);
        dp(i+1,ss,n,cn);
    }
}

int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        s.clear();
        int n,k;
        cin>>n>>k;
        c=0;
        cout<<"Case "<<test++<<":"<<endl;
        for(int i=65;i<65+n;i++) s+=(char)i;
        dp(0,s,n,k);
    }
}
