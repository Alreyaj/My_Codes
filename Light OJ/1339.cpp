#include<bits/stdc++.h>
using namespace std;
#define N 100009
#define ff first
#define ss second

int a[N];

struct node
{
    int ans;
    pair<int, int>lp, rs;
};

node tree[4 * N];

void build(int n, int b, int e)
{
    if(b == e)
    {
        tree[n].ans = 1;
        tree[n].lp.ff = 1;
        tree[n].lp.ss = a[b];
        tree[n].rs.ff = 1;
        tree[n].rs.ss = a[b];
        return;
    }
    int l = n << 1;
    int m = (b + e) >> 1;
    build(l, b, m);
    build(l | 1, m + 1, e);
    tree[n].ans = max(max(tree[l].ans, tree[l | 1].ans), (tree[l].rs.ss == tree[l | 1].lp.ss)?tree[l].rs.ff + tree[l | 1].lp.ff: 0);
    if(tree[l].lp.ff == m - b + 1 && tree[l].lp.ss == tree[l | 1].lp.ss)
    {
        tree[n].lp.ff = tree[l].lp.ff + tree[l | 1].lp.ff;
        tree[n].lp.ss = tree[l].lp.ss;
    }
    else
    {
        tree[n].lp = tree[l].lp;
    }
    if(tree[l | 1].rs.ff == e - m && tree[l | 1].rs.ss == tree[l].rs.ss)
    {
        tree[n].rs.ff = tree[l | 1].rs.ff + tree[l].rs.ff;
        tree[n].rs.ss = tree[l | 1].rs.ss;
    }
    else
    {
        tree[n].rs = tree[l | 1].rs;
    }
}

node qry(int n, int b, int e, int i, int j)
{
    if(i <= b && j >= e)
        return tree[n];
    int m = (b + e) >> 1;
    int l = n << 1;
    node x, y, aa;
    bool is1 = false, is2 = false;
    if(i <= m)
    {
        x = qry(l, b, m, i, j);
        is1 = true;
    }
    if(j > m)
    {
        is2 = true;
        y = qry(l | 1, m + 1, e, i, j);
    }
    if(is1 && is2)
    {
        aa.ans =  max(max(x.ans, y.ans), (x.rs.ss == y.lp.ss)? x.rs.ff + y.lp.ff: 0);
        if(x.lp.ff == m - b + 1 && x.lp.ss == y.lp.ss)
        {
            aa.lp.ff = x.lp.ff + y.lp.ff;
            aa.lp.ss = x.lp.ss;
        }
        else
        {
            aa.lp = x.lp;
        }
        if(y.rs.ff == e - m && y.rs.ss == x.rs.ss)
        {
            aa.rs.ff = y.rs.ff + x.rs.ff;
            aa.rs.ss = y.rs.ss;
        }
        else
        {
            aa.rs = y.rs;
        }
        return aa;
    }
    else if(is1) return x;
    else return y;
}

int main()
{
    int t, test = 1;
    //cin >> t;
    scanf("%d", &t);
    while(t--)
    {
    	memset(tree, 0, sizeof(tree));
        int n, c, q;
        //cin >> n >> c >> q;
        scanf("%d %d %d", &n, &c, &q);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        //cout << "T";
        build(1, 1, n);
        //cout << tree[1].rs.ff << endl;
        printf("Case %d:\n", test++);
        while(q--)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            node aa = qry(1, 1, n, x, y);
            printf("%d\n", aa.ans);
        }
    }
}
