#include<bits/stdc++.h>
using namespace std;
#define N 100009
#define all(x) x.begin(), x.end()

int Int()
{
	int x;
	scanf("%d", &x);
	return x;
}

vector<int> tree[4 * N];
int lst[N], pre[N];

void build(int node, int b, int e)
{
    if(b == e)
	{
        tree[node].push_back(pre[b]);
        return;
	}
	int l = node << 1;
	int m = (b + e) >> 1;
	build(l, b, m);
	build(l | 1, m + 1, e);
	merge(all(tree[l]), all(tree[l | 1]), back_inserter(tree[node]));
}

int qry(int node, int b, int e, int i, int j)
{
	if(i > e || j < b) return 0;
    if(i <= b && j >= e)
	{
		return lower_bound(all(tree[node]), i) - tree[node].begin();
	}
	int l = node << 1;
	int m = (b + e) >> 1;
	return qry(l, b, m, i, j) + qry(l | 1, m + 1, e, i, j);
}

int main()
{
	int t = Int(), test = 1;
	while(t--)
	{
		for(int i = 1; i < 4 * N; i++) tree[i].clear();
		memset(pre, 0, sizeof(pre));
		memset(lst, 0, sizeof(lst));
		int n = Int(), q = Int();
		for(int i = 1; i <= n; i++) {
				int x = Int();
				pre[i] = lst[x];
				lst[x] = i;
		}
		build(1, 1, n);
		printf("Case %d:\n", test++);
		while(q--)
		{
            int x = Int(), y = Int();
            printf("%d\n", qry(1, 1, n, x, y));
		}
	}
}
