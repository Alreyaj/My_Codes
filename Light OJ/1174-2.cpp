#include<bits/stdc++.h>
using namespace std;
const int N=109;
int dis[N];
bool bb[N];

vector<int>v[N];
int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++) v[i].clear();
        int ans=0;
        while(m--)
        {
            int u,vv;
            cin>>u>>vv;
            v[u].push_back(vv);
            v[vv].push_back(u);
        }
        int f,s;
        cin>>f>>s;
        for(int i=0; i<n; i++)
        {
            memset(dis,0,sizeof(dis));
            memset(bb,false,sizeof(bb));
            int cn;
            queue<int>q;
            q.push(f);
            dis[f]=0;
            while(!q.empty())
            {
                int u=q.front();
                bb[u]=true;
                q.pop();
                bool b=false;
                for(int j=0; j<v[u].size(); j++)
                {
                    if(!bb[v[u][j]])
                    {
                        dis[v[u][j]]=dis[u]+1;
                        if(v[u][j]==i)
                        {
                            b=true;
                            break;
                        }
                        q.push(v[u][j]);
                        bb[v[u][j]]=true;
                    }
                }
                if(b) break;
            }
            // for(int j=0;j<n;j++) cout<<dis[j]<<" ";
            // cout<<endl;
            cn=dis[i];
            memset(dis,0,sizeof(dis));
            memset(bb,false,sizeof(bb));
            while(!q.empty()) q.pop();
            q.push(i);
            dis[i]=0;
            while(!q.empty())
            {
                int u=q.front();
                bb[u]=true;
                q.pop();
                bool b=false;
                for(int j=0; j<v[u].size(); j++)
                {
                    if(!bb[v[u][j]])
                    {
                        dis[v[u][j]]=dis[u]+1;
                        if(v[u][j]==s)
                        {
                            b=true;
                            break;
                        }
                        q.push(v[u][j]);
                        bb[v[u][j]]=true;
                    }
                }
                if(b) break;
            }
            //for(int j=0;j<n;j++) cout<<dis[j]<<" ";
            // cout<<endl;
            cn+=dis[s];
           // cout<<cn<<endl;
            ans=max(ans,cn);
        }
        printf("Case %d: %d\n",test++,ans);
    }
}
