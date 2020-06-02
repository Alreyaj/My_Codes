#include<bits/stdc++.h>
#define N 100009
#define pb push_back
using namespace std;

vector<int>v[N];
bool b[N];
int lvl[N];
int cx,cy;

void dfs(int p,int n)
{
    if(!b[n]) return;
    b[n]=false;
    lvl[n]=lvl[p]+1;
    if(lvl[n]%2==0) cy++;
    else cx++;
    int l=v[n].size();
    for(int i=0;i<l;i++) dfs(n,v[n][i]);
}
int main()
{
    int t=1,test;
    cin>>test;
    while(test--)
    {
        int n,m=0;
        cin>>n;
        for(int i=1;i<=N;i++) v[i].clear();
        for(int i=1;i<=n;i++)
        {
            int x,y;
            cin>>x>>y;
            b[x]=true;
            b[y]=true;
            if(x>m) m=x;
            if(y>m) m=y;
            v[x].pb(y);
            v[y].pb(x);
        }
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            if(b[i])
            {
                cx=0;cy=0;
                dfs(0,i);
                ans+=max(cx,cy);
            }
        }
        cout<<"Case "<<t++<<": "<<ans<<endl;
    }
    return 0;
}
