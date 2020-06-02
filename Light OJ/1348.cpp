#include<bits/stdc++.h>
using namespace std;
#define N 30009
#define pb push_back
int a[N], st[N], en[N], par[N][20], tmm, lvl[N], tree[N * 4], lz[N * 4];
vector<int> v[N];

void dfs(int n, int p)
{
	lvl[n] = p == -1? 1 : (lvl[p] + 1);
    st[n] = ++tmm;
    par[n][0] = p;
    for(int i = 1; i < 20; i++)
	{
        if(par[n][i - 1] != -1) par[n][i] = par[par[n][i - 1]][i - 1];
	}
	for(int x: v[n])
	{
		if(x != p) dfs(x, n);
	}
	en[n] = tmm;
}

void upd(int node, int b, int e, int i, int j, int val)
{
	int l = node << 1;
    if(lz[node])
	{
		tree[node] += (e - b + 1) * lz[node];
		if(b != e)
		{
			lz[l] += lz[node];
			lz[l | 1] += lz[node];
		}
		lz[node] = 0;
	}
	if(i > e || j < b) return;
	if(i <= b && j >= e)
	{
		tree[node] += (e - b + 1) * val;
		if(b != e)
		{
			lz[l] += val;
			lz[l | 1] += val;
		}
		return;
	}
	int m = (b + e) >> 1;
	upd(l, b , m, i, j, val);
	upd(l | 1, m + 1, e, i, j, val);
	tree[node] = tree[l] + tree[l | 1];
}

int qry(int node, int b, int e, int i, int j)
{
	int l = node << 1;
    if(i > e || j < b) return 0;
    if(lz[node])
	{
		tree[node] += (e - b + 1) * lz[node];
		if(b != e)
		{
			lz[l] += lz[node];
			lz[l | 1] += lz[node];
		}
		lz[node] = 0;
	}
	if(i <= b && j >= e) return tree[node];
	int m = (b + e) >> 1;
	return qry(l, b, m, i, j) + qry(l | 1, m + 1, e, i, j);
}

int lca(int x, int y)
{
	if(lvl[x] < lvl[y]) swap(x, y);
	for(int i = 19; i >=0; i--)
	{
		if(lvl[x] - (1 << i) >= lvl[y])
		{
			x = par[x][i];
		}
	}
	if(x == y) return x;
	for(int i = 19; i >= 0; i--)
	{
		if(par[x][i] != -1 && par[x][i] != par[y][i])
		{
			x = par[x][i];
			y = par[y][i];
		}
	}
	return par[x][0];
}

int main()
{
    int t, test = 1;
    scanf("%d", &t);
    while(t--)
	{
		tmm = 0;
		memset(par, -1, sizeof(par));
		memset(tree, 0, sizeof(tree));
		memset(lz, 0, sizeof(lz));
		for(int i = 0; i < N; i++) {
				v[i].clear();
				a[i] = st[i] = en[i] = lvl[i] = 0;
		}
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		for(int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			v[x].pb(y);
			v[y].pb(x);
		}
		dfs(0, -1);
		for(int i = 0; i < n; i++)
		{
			//cout << st[i] << " " << en[i] << endl;
			upd(1, 1, n, st[i], en[i], a[i]);
		}
		printf("Case %d:\n", test++);
		int q;
		scanf("%d", &q);
		while(q--)
		{
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			if(x)
			{
				upd(1, 1, n, st[y], en[y], z - a[y]);
				a[y] = z;
			}
			else{
					int pr = lca(y, z);
				printf("%d\n", qry(1, 1, n, st[y], st[y]) + qry(1, 1, n, st[z], st[z]) - 2 * qry(1, 1, n, st[pr], st[pr]) + a[pr]);
			}
		}
	}
}
