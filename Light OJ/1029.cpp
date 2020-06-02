#include<bits/stdc++.h>
using namespace std;

const int N=105;

struct data{
    int u,v,w;
};

bool com(data x,data y)
{
    if(x.w<y.w) return true;
    return false;
}

data dt[12005];
int pa[N],pb[N];

int fnd1(int x)
{
    if(pa[x]==x) return x;
    return pa[x]=fnd1(pa[x]);
}
int fnd2(int x)
{
    if(pb[x]==x) return x;
    return pb[x]=fnd2(pb[x]);
}
void un1(int x,int y)
{
    x=fnd1(x);
    y=fnd1(y);
    pa[x]=y;
}
void un2(int x,int y)
{
    x=fnd2(x);
    y=fnd2(y);
    pb[x]=y;
}



int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<N;i++)
        {
            pa[i]=i;
            pb[i]=i;
        }
        int n,c=0;
        cin>>n;
        for(;c<12005;c++)
        {
            cin>>dt[c].u>>dt[c].v>>dt[c].w;
            if(dt[c].u==0&&dt[c].v==0&&dt[c].w==0) break;
        }
        sort(dt,dt+c,com);
        int a1=0,a2=0;
        for(int i=0;i<c;i++)
        {
            if(fnd1(dt[i].u)!=fnd1(dt[i].v))
            {
                un1(dt[i].u,dt[i].v);
                a1+=dt[i].w;
            }
            if(fnd2(dt[c-i-1].u)!=fnd2(dt[c-i-1].v))
            {
                un2(dt[c-1-i].u,dt[c-1-i].v);
                a2+=dt[c-1-i].w;
            }
        }
        a1+=a2;
        printf("Case %d: ",test++);
        if(a1%2==0) cout<<a1/2<<endl;
        else cout<<a1<<"/2"<<endl;

    }
}
