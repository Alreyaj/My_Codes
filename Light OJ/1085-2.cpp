#include<bits/stdc++.h>
using namespace std;
#define N 100009
#define ff first
#define ss second
#define pii pair<int,int>
#define mod 1000000007
#define ll int
ll a[N],cn[N],ps[N],tree[N];
pair<ll,int>pr[N];

bool comp(pii x, pii y)
{
    if(x.ff<y.ff) return true;
    if(x.ff==y.ff) return x.ss<y.ss;
    return false;
}

void upd(int n,ll v)
{
    while(n<N)
    {
        tree[n]=(tree[n]+v)%mod;
        n+=(n&(-n));
    }
}

int qry(int n)
{
    ll ans = 0;
    while(n>0)
    {
        ans=(ans+tree[n])%mod;
        n-=(n&(-n));
    }
    return ans;
}

int main()
{
    int t,test=1,n;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1;i<N;i++) tree[i] = 0;
        //memset(tree,0,sizeof(tree));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            pr[i] = {a[i],i};
        }
        sort(pr+1,pr+n+1);
        ll x=1;
        a[pr[1].ss]=x;
        for(int i=2;i<=n;i++)
        {
            if(pr[i].ff==pr[i-1].ff) a[pr[i].ss]=x;
            else a[pr[i].ss]=++x;
        }
        ll ans=0,c=0;
        //cout<<pr[0].ff<<endl;
        for(int i = 1; i <= n; i++)
        {
            ll sm = qry(a[i]-1)+1;
            upd(a[i],sm);
            //cout<<ps[i]<<endl;
            ans=(ans+sm)%mod;
        }
        printf("Case %d: %d\n",test++,ans);
    }
}
