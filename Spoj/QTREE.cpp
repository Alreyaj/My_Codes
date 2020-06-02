#include<bits/stdc++.h>
using namespace std;
#define N 10005

vector<int>adj[N], lst[N], tree[N];
int sz[N], dep[N], par[N][20], idx[N], pos[N], cn = 1, arr[N];
pair<int, int> edj[N];
int mp[N][N];

void dfs(int n, int p)
{
    sz[n] = 1;
    dep[n] = dep[p] + 1;
    par[n][0] = p;
    for(int i = 1; i < 20; i++)
    {
        par[n][i] = par[par[n][i - 1]][i - 1];
    }
    for(int x : adj[n])
    {
        if(x != p)
        {
            arr[x] = mp[x][n];
            mp[x][n] = mp[n][x] = x;
            dfs(x, n);
            sz[n] += sz[x];
        }
    }
}

int lca(int x, int y)
{
    if(dep[x] < dep[y])
        swap(x, y);
    for(int i = 19; i >= 0; i--)
    {
        if(dep[par[x][i]] >= dep[y])
            x = par[x][i];
    }
    if(x == y)
        return x;
    for(int i = 19; i >= 0; i--)
    {
        if(par[x][i] != par[y][i])
            x = par[x][i], y = par[y][i];
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
        if(x != p && sz[x] > mx)
            mx = sz[x], heavy = x;
    }
    if(mx)
        hld(heavy, n);
    for(int x : adj[n])
    {
        if(x != p && x != heavy)
            ++cn, hld(x, n);
    }
}

void process()
{
    for(int i = 1; i <= cn; i++)
    {
        for(int j = 0; j <= 4 * lst[i].size(); j++)
            tree[i].push_back(0);
    }
}

void tree_upd(int nm, int node, int b, int e, int pos, int val)
{
    if(pos < b || pos > e)
        return;
    //cout << b <<" " << e << endl;
    if(b == e)
    {
        tree[nm][node] = val;
        return;
    }
    int lf = node * 2;
    int rt = lf + 1;
    int md = (b + e) / 2;
    tree_upd(nm, lf, b, md, pos, val);
    tree_upd(nm, rt, md + 1, e, pos, val);
    tree[nm][node] = max(tree[nm][lf], tree[nm][rt]);
}

int tree_qry(int nm, int node, int b, int e, int l, int r)
{
    if(l > e || r < b)
        return 0;
    //cout << b <<" " << e << endl;
    if(l <= b && r >= e)
        return tree[nm][node];
    int lf = node * 2;
    int rt = lf + 1;
    int md = (b + e) / 2;
    return max(tree_qry(nm, lf, b, md, l, r), tree_qry(nm, rt, md + 1, e, l, r));
}

void upd(int n, int v)
{
    tree_upd(idx[n], 1, 1, lst[idx[n]].size(), pos[n], v);
}



int qry(int x, int y)
{
    int res = 0;
    while(1)
    {
        //cout << pos[x] << " " << pos[y] << endl;
        if(idx[x] == idx[y])
        {
            //cout << tree_qry(idx[x], 1, 1, lst[idx[x]].size(), pos[y], pos[x]) << endl;
            return res = max(res, tree_qry(idx[x], 1, 1, lst[idx[x]].size(), pos[y] + 1, pos[x]));
        }
        else
            res = max(res, tree_qry(idx[x], 1, 1, lst[idx[x]].size(), 1, pos[x]));
        x = par[lst[idx[x]][0]][0];
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    scanf("%d", &t);
    while(t--)
    {
    //cout << "T" << endl;
        cn = 1;
        int n;
        scanf("%d", &n);
        for(int i = 0; i <= n; i++)
            adj[i].clear(), lst[i].clear(), tree[i].clear();
        for(int i = 1; i < n; i++)
        {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            adj[x].push_back(y);
            adj[y].push_back(x);
            edj[i] = {x, y};
            mp[x][y] = z;
            mp[y][x] = z;
        }
        dfs(1, 0);
        hld(1, 0);
        process();
        for(int i = 1; i <= n ; i++)
            upd(i, arr[i]);
        while(1)
        {
            //cout <<"T";
            char ch[10];
            int x, y;
            scanf(" %s", ch);
            if(ch[0] == 'C')
            {
                scanf("%d %d", &x, &y);
                //cout << mp[edj[x]] << endl;
                upd(mp[edj[x].first][edj[x].second], y);
                //cout << tree[idx[x]][1] << endl;
            }
            else if(ch[0] == 'Q')
            {
                scanf("%d %d", &x, &y);
                int l = lca(x, y);
                //cout << tree[1][1] << endl;
                printf("%d\n", max(qry(x, l), qry(y, l)));
            }
            else
                break;
        }
    }
}

