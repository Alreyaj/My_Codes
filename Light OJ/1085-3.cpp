#include<bits/stdc++.h>
using namespace std;
#define N 100009
#define ff first
#define ss second
#define pii pair<int,int>
#define mod 1000000007
#define ll int
ll a[N],tree[4*N];
pair<ll,int>pr[N];

bool comp(pii x, pii y)
{
    if(x.ff<y.ff) return true;
    if(x.ff==y.ff) return x.ss<y.ss;
    return false;
}


void update(int node, int b, int e, int pos, ll v)
{
    if(pos > e || pos < b) return;
    if(b == e)
    {
        tree[node] = (tree[node] + v) % mod;
        return;
    }
    int l = node << 1;
    int m = (b + e) >> 1;
    update(l, b, m, pos, v);
    update(l | 1, m + 1, e, pos, v);
    tree[node] = (tree[l] + tree[l | 1]) % mod;
}

ll qry(int node, int b, int e, int i, int j)
{
    if(i > e || j < b) return 0;
    if(i <= b && j >= e) return tree[node];
    int l = node << 1;
    int m = (b + e) >> 1;
    return (qry(l, b, m, i, j) + qry(l | 1, m + 1, e, i, j)) % mod;
}


int main()
{
    int t,test = 1,n;
    scanf("%d",&t);
    while(t--)
    {
        memset(tree, 0, sizeof(tree));
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
        //for(int i = 1; i <= n; i++) cout << a[i] << " ";
        ll ans=0;
        for(int i = 1; i <= n; i++)
        {
            ll sm = qry(1, 1, 100000, 1, a[i] - 1) + 1;
            //cout << sm << endl;
            update(1, 1, 100000, a[i], sm);
            //for(int i = 1; i <= 4*n; i++) cout << tree[i] << " ";
            ans = (ans + sm) % mod;
        }

        printf("Case %d: %d\n",test++,ans);
    }
}
