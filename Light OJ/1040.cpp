#include<bits/stdc++.h>
using namespace std;
const int N=55;

struct data
{
    int u,v,w;
};

bool com(data x,data y)
{
    if(x.w<y.w) return true;
    return false;
}

data dt[2505];
int p[N];
bool b[N];
vector<int>v[N];

int fnd(int x)
{
    if(p[x]==x) return x;
    return p[x]=fnd(p[x]);
}
void un(int x,int y)
{
    x=fnd(x);
    y=fnd(y);
    p[x]=y;
}

void dfs(int n)
{
    if(b[n]) return;
    b[n]=true;
    int l=v[n].size();
    for(int i=0;i<l;i++) dfs(v[n][i]);
}
int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        for(int i=0; i<N; i++)
        {
            v[i].clear();
            p[i]=i;
            b[i]=false;
        }
        int n,ans=0,c=0;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int x;
                cin>>x;
                if(i==j) ans+=x;
                else if(x!=0)
                {
                    dt[c].u=i;
                    dt[c].v=j;
                    dt[c].w=x;
                    c++;
                }
            }
        }
        sort(dt,dt+c,com);
        //for(int i=0; i<c; i++) cout<<dt[i].u<<" "<<dt[i].v<<" "<<dt[i].w<<endl;
        for(int i=0; i<c; i++)
        {
            if(fnd(dt[i].u)!=fnd(dt[i].v))
            {
                v[dt[i].u].push_back(dt[i].v);
                v[dt[i].v].push_back(dt[i].u);
                un(dt[i].u,dt[i].v);
            }
            else ans+=dt[i].w;
        }
        dfs(0);
        bool is=false;
        printf("Case %d: ",test++);
        for(int i=0; i<n; i++)
        {
            if(!b[i])
            {
                cout<<"-1"<<endl;
                is=true;
                break;
            }
        }
        if(!is) cout<<ans<<endl;
    }
}
