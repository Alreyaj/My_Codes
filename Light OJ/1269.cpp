#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 50009
#define pt 2

int  node[N * 33][pt], idx = 2, cn[N * 33];


void ins(ll x)
{
    int nw = 1;
    for(int i = 32; i >= 0; i--)
    {
        ll v = (1LL & (x >> i));
        if(node[nw][v] == 0) node[nw][v] = idx++;
        nw =  node[nw][v];
        cn[nw]++;
    }

}

//void dlt(ll x)
//{
//    int nw = 1;
//    for(int i = 32; i >= 0; i--)
//    {
//        ll v = (1LL & (x >> i));
//        nw =  node[nw][v];
//        cn[nw]--;
//    }
//}

ll cal(ll x)
{
    int now = 1;
    ll res = 0LL;
    for(int i = 32; i >= 0; i--)
    {
        ll v = (1LL & (x >> i));
        if(node[now][v] && cn[node[now][v]]) {
                //cout <<"Y";
                now = node[now][v];
                res = res | (v << i);
        }
        else {
            //cout <<"N";
                now = node[now][(v ^ 1LL)];
                res = res | ((v ^ 1LL) << i);
        }
    }
    //cout << endl;
    return res;
}

ll a[N];

int main()
{
    int t, ts = 1;
    scanf("%d", &t);
    while(t--)
    {
        memset(node, 0, sizeof(node));
        memset(cn, 0, sizeof(cn));
        idx = 2;
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
                scanf("%lld", &a[i]);
        }
        ll mx = 0LL, mn = LLONG_MAX, sum = 0LL;
        ins(sum);
        for(int i = 1; i <= n; i++)
        {
            //dlt(a[i]);
            ll nmx = 0LL;
            sum = sum ^ a[i];
            for(int j = 32; j >= 0; j--)
            {
                ll dg = (1LL & sum >> j);
                //cout << (dg);
                nmx = nmx | ((dg ^ 1LL) << j);
            }
            //cout << endl;
            //cout << cal(nmx) << endl;
            mx = max(mx, (sum ^ cal(nmx)));
            mn = min(mn, (sum ^ cal(sum)));
            ins(sum);
        }
        printf("Case %d: %lld %lld\n", ts++, mx, mn);

    }
}


