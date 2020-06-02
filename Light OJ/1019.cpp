#include<bits/stdc++.h>
using namespace std;
const int N=109;

#define pii pair<int,int>
priority_queue<pii,vector<pii>,greater<pii> >Q;

int dis[N];
vector<pii> v[N];

void Dijkstra()
{
    Q.push(make_pair(0,1));
    dis[1]=0;
    while(!Q.empty())
    {
        int u=Q.top().second;
        Q.pop();
        for(int i=0;i<v[u].size();i++)
        {
            pii x=v[u][i];
            if(dis[x.first]>dis[u]+x.second)
            {
                dis[x.first]=dis[u]+x.second;
                Q.push(make_pair(dis[x.first],x.first));
            }

        }
    }
}
int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            dis[i]=INT_MAX;
            v[i].clear();
        }
        for(int i=0;i<m;i++)
        {
            int u, vv, w;
            scanf("%d%d%d",&u,&vv,&w);
            v[u].push_back(make_pair(vv, w));
            v[vv].push_back(make_pair(u, w));
        }
        Dijkstra();
        if(dis[n]==INT_MAX) printf("Case %d: Impossible\n",test++);
        else printf("Case %d: %d\n",test++,dis[n]);
    }
}
