#include<bits/stdc++.h>
using namespace std;
#define N 100009
#define ll long long
struct tree
{
    ll val;
    ll p;
};

tree st[4*N];

void build(ll node,ll b,ll e)
{
    if(b==e)
    {
        st[node].val= 0;
        return;
    }
    ll l=node*2;
    ll r=l+1;
    ll m=(b+e)/2;
    build(l,b,m);
    build(r,m+1,e);
    st[node].val=st[l].val+st[r].val;
}

void update(ll node,ll b,ll e,ll i,ll j,ll v)
{
    ll l=node*2;
    ll r=l+1;
    if(st[node].p)
    {
        st[node].val += (e - b + 1) * st[node].p;
        if(b != e)
        {
            st[l].p += st[node].p;
            st[r].p += st[node].p;
        }
        st[node].p = 0;
    }
    if(i>e||j<b) return;
    if(i<=b&&j>=e)
    {
        st[node].val+=v*(e-b+1);
        if(b != e)
        {
            st[l].p += v;
            st[r].p += v;
        }
        return;
    }
    ll m=(b+e)/2;
    update(l,b,m,i,j,v);
    update(r,m+1,e,i,j,v);
    st[node].val=st[l].val+st[r].val;
}

ll qry(ll node,ll b,ll e, ll i, ll j)
{
    ll l=node*2;
    ll r=l+1;
    if(i>e||j<b) return 0;
    if(st[node].p)
    {
        st[node].val += (e - b + 1) * st[node].p;
        if(b != e)
        {
            st[l].p += st[node].p;
            st[r].p += st[node].p;
        }
        st[node].p = 0;
    }
    if(i<=b&&j>=e)
    {
        return st[node].val;
    }
    ll m=(b+e)/2;
    return qry(l,b,m,i,j)+qry(r,m+1,e,i,j);
}


int main()
{
    ll t, test = 1, n, q, tp, x, y;
    scanf("%d", &t);
    while(t--)
    {
        for(ll i = 1; i < 4 * N; i++)
        {
            st[i] = {0, 0};
        }
        scanf("%lld %lld", &n, &q);
        printf("Case %lld:\n", test++);
        build(1, 1, n);
        while(q--)
        {
             scanf("%lld %lld %lld", &tp, &x, &y);
             x++, y++;
             if(tp)
             {
                 printf("%lld\n", qry(1, 1, n, x, y));
             }
             else
             {
                 ll v;
                 scanf("%lld", &v);
                 update(1, 1, n, x, y, v);
             }
        }
    }
}

