#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define LG 20

vector<int>adj[N], lst[N], tree[N];
int sz[N], dep[N], par[N][LG], idx[N], pos[N], cn = 1, arr[N];

void dfs(int n, int p)
{
    sz[n] = 1;
    dep[n] = dep[p] + 1;
    par[n][0] = p;
    for(int i = 1; i < LG; i++)
    {
        par[n][i] = par[par[n][i - 1]][i - 1];
    }
    for(int x : adj[n])
    {
        if(x != p)
        {
            dfs(x, n);
            sz[n] += sz[x];
        }
    }
}

int lca(int x, int y)
{
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = LG - 1; i >= 0; i--)
    {
        if(dep[par[x][i]] >= dep[y]) x = par[x][i];
    }
    if(x == y) return x;
    for(int i = LG - 1; i >= 0; i--)
    {
        if(par[x][i] != par[y][i]) x = par[x][i], y = par[y][i];
    }
    return par[x][0];
}

void hld(int n, int p)
{
    lst[cn].push_back(n);
    idx[n] = cn;
    pos[n] = int(lst[cn].size());
    int heavy = -1, mx = 0;
    for(int x : adj[n])
    {
        if(x != p && sz[x] > mx) mx = sz[x], heavy = x;
    }
    if(mx) hld(heavy, n);
    for(int x : adj[n])
    {
        if(x != p && x != heavy) ++cn, hld(x, n);
    }
}

void process()
{
    for(int i = 1; i <= cn; i++)
    {
        for(int j = 0; j <= 4 * lst[i].size(); j++) tree[i].push_back(100000000);
    }
}

void tree_upd(int nm, int node, int b, int e, int pos)
{
    if(pos < b || pos > e) return;
    if(b == e) {
    //cout << lst[nm][pos - 1] << endl;
    tree[nm][node] = (arr[lst[nm][pos - 1]]? lst[nm][pos - 1]: 100000000);
    return;
    }
    int lf = node * 2;
    int rt = lf + 1;
    int md = (b + e) / 2;
    tree_upd(nm, lf, b, md, pos);
    tree_upd(nm, rt, md + 1, e, pos);
    tree[nm][node] = (tree[nm][lf] != 100000000? tree[nm][lf]: tree[nm][rt]);
}

int tree_qry(int nm, int node, int b, int e, int l, int r)
{
    if(l > e || r < b) return 100000000;
    if(l <= b && r >= e) return tree[nm][node];
    int lf = node * 2;
    int rt = lf + 1;
    int md = (b + e) / 2;
    int cal = (tree_qry(nm, lf, b, md, l, r));
    return  cal != 100000000? cal : tree_qry(nm, rt, md + 1, e, l, r);
}

void upd(int n)
{
//cout << pos[n] << endl;
    tree_upd(idx[n], 1, 1, lst[idx[n]].size(), pos[n]);
}



int qry(int x)
{
    int res = 100000000;
    while(1)
    {
        if(idx[x] == idx[1])
        {
            int temp = tree_qry(idx[x], 1, 1, lst[idx[x]].size(), pos[1], pos[x]);
            res = temp == 100000000? res : temp;
            return res == 100000000? - 1 : res;
        }
        else {
        int temp = tree_qry(idx[x], 1, 1, lst[idx[x]].size(), 1, pos[x]);
        res = temp == 100000000? res : temp;
        }
        x = par[lst[idx[x]][0]][0];
    }
}

int main()
{
    int n, q;
    scanf("%d", &n);
    scanf("%d", &q);
    for(int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    hld(1, 0);
    process();
    while(q--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        if(x == 0)
        {
            arr[y] ^= 1;
            upd(y);
            //cout << tree[1][1] << endl;
        }
        else
        {
            printf("%d\n", qry(y));
        }
    }
}

