#include<bits/stdc++.h>
using namespace std;

string s,ans;
int c;

bool b[100];
void dp(int i,int n,int cn)
{
    if(c>=cn) return;
    if(i==n)
    {
        cout<<ans<<endl;
        c++;
        return;
    }
    for(int j=0;j<n;j++)
    {
        if(c>=cn) return;
        if(!b[j])
        {
            ans[i]=s[j];
            b[j]=true;
            dp(i+1,n,cn);
            b[j]=false;
        }
    }
}
int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        ans.clear();
        s.clear();
        int n,k;
        cin>>n>>k;
        memset(b,false,sizeof(b));
        c=0;
        cout<<"Case "<<test++<<":"<<endl;
        for(int i=65;i<65+n;i++) s+=(char)i,ans+=" ";
        dp(0,n,k);
        //cout<<s<<endl;
    }
}
