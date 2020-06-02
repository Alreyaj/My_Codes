#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=30009;
vector<pii>v[N];
int ans;

int dfs(int n,int p)
{
    priority_queue<int>pq;
    int d=0;
    for(int i=0; i<v[n].size(); i++)
    {
        if(v[n][i].first!=p)
        pq.push(v[n][i].second+dfs(v[n][i].first,n));
    }
    if(!pq.empty())
    {
        d=pq.top();
        pq.pop();
        ans=max(ans,d+(pq.empty()?0:pq.top()));
    }
    //cout<<d<<endl;
    return d;
}

int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        ans=0;
        int n;
        cin>>n;
        for(int i=0; i<n; i++) v[i].clear();
        for(int i=0; i<n-1; i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            v[x].push_back(make_pair(y,z));
            v[y].push_back(make_pair(x,z));
        }
        int x=dfs(0,0);
        printf("Case %d: %d\n",test++,ans);
    }
}
