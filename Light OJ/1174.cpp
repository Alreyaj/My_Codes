#include<bits/stdc++.h>
using namespace std;
const int N=109;
long long dis[N][N];


int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++) if(i!=j) dis[i][j]=INT_MAX;
        }
        long long ans=0;
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            dis[u][v]=1;
            dis[v][u]=1;
        }
        int f,s;
        cin>>f>>s;
        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                    dis[j][i]=dis[i][j];
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            ans=max(ans,dis[f][i]+dis[i][s]);
        }
        printf("Case %d: %lld\n",test++,ans);
    }
}
