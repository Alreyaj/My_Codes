#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int N=30009;
vector<pii>v[N];
int ans,p1,p2;
int dis[N];

pii dfs(int n,int p)
{
	//cout<<n<<endl;
    priority_queue<pii>pq;
    pii d;d.second=n;
    for(int i=0; i<v[n].size(); i++)
    {
        if(v[n][i].first!=p){
        pii xx=dfs(v[n][i].first,n);
            pq.push(make_pair(v[n][i].second+xx.first,xx.second));
            }
    }
    if(!pq.empty())
    {
        d=pq.top();
        pq.pop();
        if(!pq.empty())
        {
            if(d.first+pq.top().first>ans)
            {
                ans=d.first+pq.top().first;
                p1=d.second;
                p2=pq.top().second;
            }
        }
        else
        {
            if(d.first>ans)
            {
                ans=d.first;
                p1=d.second;
                p2=n;
            }
        }
        //ans=max(ans,d+(pq.empty()?0:pq.top()));
    }
    //cout<<n<<" "<<d.first<<" "<<d.second<<endl;
    return d;
}

void dfs2(int n,int p,int d)
{
     //cout<<n<<endl;
	for(int i=0;i<v[n].size();i++)
	{
        if(v[n][i].first!=p)
        {
            dis[v[n][i].first]=max(dis[v[n][i].first],d+v[n][i].second);
            dfs2(v[n][i].first,n,d+v[n][i].second);
        }
	}
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
        for(int i=0; i<n; i++) v[i].clear(),dis[i]=0;
        for(int i=0; i<n-1; i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            v[x].push_back(make_pair(y,z));
            v[y].push_back(make_pair(x,z));
        }
        pii x=dfs(0,0);
        dfs2(p1,p1,0);
        dfs2(p2,p2,0);
        //cout<<ans<<" "<<p1<<" "<<p2<<endl;
        printf("Case %d:\n",test++);
        for(int i=0;i<n;i++) printf("%d\n",dis[i]);
    }

}
