#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
priority_queue<pii,vector<pii>,greater<pii> >Q;
const int N=5009;

int dis1[N],dis2[N];
bool b[N];
vector<pii> v[N];
void Dijkstra()
{
    Q.push(make_pair(0,1));
    dis1[1]=0;
    int mn=INT_MAX;
    for(int i=0;i<v[1].size();i++) mn=min(mn,v[1][i].second);
    dis2[1]=2*mn;
    while(!Q.empty())
    {
        int u=Q.top().second;
        Q.pop();
        for(int i=0;i< v[u].size();i++)
        {
            pii x=v[u][i];
            if( dis1[ x.first ] > dis1[ u ] + x.second ) {
                    int r=dis1[x.first];
                    dis1[ x.first ] = dis1[ u ] + x.second;
                    dis2[x.first]=min(dis1[x.first] +2*(x.second),min(dis2[u]+x.second,r));
                    //cout<<x.first<<" "<<dis2[x.first]<<endl;
                    Q.push(make_pair(dis1[x.first],x.first));
            }
            else
            {
                //if(!b[x.first])
               // {
                    if(dis2[x.first] > dis1[ u ] + x.second && dis1[x.first]<dis1[ u ] + x.second) dis2[x.first] = dis1[ u ] + x.second;
                //    b[x.first]=true;
                //}
            }
        }
    }
}

int main()
{
    int t,test=1;
    cin>> t ;
    while(t--)
    {
        int n, m;
        cin>> n >> m;
        for(int i=1; i<=n; i++)
        {
            b[i]=false;
            v[i].clear();
            dis1[i]=INT_MAX;
            dis2[i]=INT_MAX;
        }
        for(int i = 0; i < m; i++)
        {
            int u, vv, w;
            scanf("%d%d%d",&u,&vv,&w);
            v[u].push_back(make_pair(vv, w));
            v[vv].push_back(make_pair(u, w));
        }
        Dijkstra();
       // for(int i=1; i<=n; i++)
       // {
       ///     cout<<dis1[i]<<" "<<dis2[i]<<endl;
       // }
        printf("Case %d: %d\n",test++,dis2[n]);
    }
}
