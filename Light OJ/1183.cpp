#include<bits/stdc++.h>
using namespace std;
#define N 100009
#define ff first
#define ss second

pair<int, int> tree[4 * N];

void build(int node, int b, int e)
{
    if(b == e)
    {
        tree[node].ff = 0;
        return;
    }
    int l = node << 1;
    int r = l | 1;
    int m = (b + e) >> 1;
    build(l, b, m);
    build(r, m + 1, e);
    tree[node].ff = tree[l].ff + tree[r].ff;
}

void upd(int node, int b, int e, int i, int j, int v)
{
    int l = node << 1;
    int r = l | 1;
    if(tree[node].ss != -1)
    {
        tree[node].ff = (e - b + 1) * tree[node].ss;
        if(b != e)
        {
            tree[l].ss = tree[node].ss;
            tree[r].ss = tree[node].ss;
        }
        tree[node].ss = -1;
    }
    if(i > e || j < b) return;
    if(i <= b && j >= e)
    {
        tree[node].ff = (e - b + 1) * v;
        if(b != e)
        {
            tree[l].ss = v;
            tree[r].ss = v;
        }
        return;
    }
    int m = (b + e) >> 1;
    upd(l, b, m, i, j, v);
    upd(r, m + 1, e, i, j, v);
    tree[node].ff = tree[l].ff + tree[r].ff;
}

int qry(int node, int b, int e,int i, int j)
{
    if(i > e || j < b) return 0;
    int l = node << 1;
    int r = l | 1;
    if(tree[node].ss != -1)
    {
        tree[node].ff = (e - b + 1) * tree[node].ss;
        if(b != e)
        {
            tree[l].ss = tree[node].ss;
            tree[r].ss = tree[node].ss;
        }
        tree[node].ss = -1;
    }
    if(i <= b && j >= e)
    {
        return tree[node].ff;
    }
    int m = (b + e) >> 1;
    return qry(l, b, m, i, j) + qry(r, m + 1, e, i, j);
}

int main()
{
    int t, test = 1, n, q;
    scanf("%d", &t);
    while(t--)
    {
        for(int i = 1; i < 4 * N; i++) tree[i] = {0, -1};
        //memset(tree, 0, sizeof(tree));
        printf("Case %d:\n", test++);
        scanf("%d %d", &n, &q);
        int tp, x, y, v;
        while(q--)
        {
            scanf("%d %d %d", &tp, &x, &y);
            x++, y++;
            if(tp == 1)
            {
                scanf("%d", &v);
                upd(1, 1, n, x, y, v);
            }
            else
            {
                int ans = qry(1, 1, n, x, y);
                //cout<< ans << endl;
                int dis = (y - x + 1);
                int gc = __gcd(ans, dis);
                ans /= gc;
                dis /= gc;
                if(dis == 1) printf("%d\n", ans);
                else printf("%d/%d\n", ans, dis);
            }
        }
    }
}
