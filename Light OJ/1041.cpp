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
    for(int i=0; i<l; i++) dfs(v[n][i]);
}
int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        map<string,int>mp;
        for(int i=1; i<N; i++)
        {
            v[i].clear();
            p[i]=i;
            b[i]=false;
        }
        int m,x,c=1,c2=0;
        string s1,s2;
        cin>>m;
        for(int i=0; i<m; i++)
        {
            cin>>s1>>s2>>x;
            if(mp[s1]==0)
            {
                mp[s1]=c++;
            }
            if(mp[s2]==0)
            {
                mp[s2]=c++;
            }
            dt[c2].u=mp[s1];
            dt[c2].v=mp[s2];
            dt[c2].w=x;
            c2++;
        }
        sort(dt,dt+c2,com);
        int ans=0;
        //for(int i=0; i<c2; i++) cout<<dt[i].u<<" "<<dt[i].v<<" "<<dt[i].w<<endl;
        for(int i=0; i<c2; i++)
        {
            if(fnd(dt[i].u)!=fnd(dt[i].v))
            {
                v[dt[i].u].push_back(dt[i].v);
                v[dt[i].v].push_back(dt[i].u);
                un(dt[i].u,dt[i].v);
                ans+=dt[i].w;
            }
        }
        dfs(1);
        bool is=false;
        printf("Case %d: ",test++);
        for(int i=1; i<c; i++)
        {
            if(!b[i])
            {
                cout<<"Impossible"<<endl;
                is=true;
                break;
            }
        }
        if(!is) cout<<ans<<endl;
    }
}
