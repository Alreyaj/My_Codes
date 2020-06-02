#include<bits/stdc++.h>
using namespace std;
#define N 100009

int a[N], id[N], ans[N], tree[4 * N];
struct pr{
    int l, r, idx;
};

pr tr[N];

bool cmp(pr a, pr b)
{
    if(a.r == b.r) return a.l < b.l;
    return a.r < b.r;
}

void upd(int node, int b, int e, int pos, int v)
{
    if(b == e)
    {
        tree[node] = v;
        return;
    }
    int m = (b + e) >> 1;
    int l = node << 1;
    if(pos <= m) upd(l, b, m, pos, v);
    else upd(l | 1, m + 1, e, pos, v);
    tree[node] = tree[l] + tree[l | 1];
}

int qry(int node, int b, int e, int pos)
{
    if(pos > e) return 0;
    if(pos <= b) return tree[node];
    int m = (b + e) >> 1;
    int l = node << 1;
    return qry(l, b, m, pos) + qry(l | 1, m + 1, e, pos);
}

int main()
{
    int t, test = 1;
    scanf("%d", &t);
    while(t--)
    {
        memset(tree, 0, sizeof(tree));
        memset(id, 0, sizeof(id));
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= q; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            tr[i] = {x, y, i};
        }
        sort(tr + 1, tr + 1 + q, cmp);
        int nr = 1;
        for(int i = 1; i <= q; i++)
        {
            while(nr <= tr[i].r)
            {
                upd(1, 1, n, nr, 1);
                if(id[a[nr]]) upd(1, 1, n, id[a[nr]], 0);
                id[a[nr]] = nr;
                nr++;
            }
            ans[tr[i].idx] = qry(1, 1, n, tr[i].l);
        }
        printf("Case %d:\n", test++);
        for(int i = 1; i <= q; i++) printf("%d\n", ans[i]);
    }
}
