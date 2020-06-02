///----------------------///
///---Code Written by----///
///-----Al-Shahreyaj-----///
///----------------------///
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define vin vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define pq priority_queue
#define all(x) x.begin(),x.end()
#define mod 1000000007
#define cone __builtin_popcount
#define conel __builtin_popcountll
typedef vector<vector<ll> > matrixl;
typedef vector<vector<int> > matrix;
#define N 100009
int Int()
{
    int x;
    scanf("%d", &x);
    return x;
}




pii tree[8 * N];
int cn[N];

void upd(int node, int b, int e, int i, int j, int v)
{
	if(tree[node].ss)
	{
		tree[node].ff = tree[node].ss;
		if(b != e)
		{
			tree[node << 1].ss = tree[node].ss;
			tree[(node << 1) | 1].ss = tree[node].ss;
		}
		tree[node].ss = 0;
	}
	if(i > e || j < b) return;
	if(i <= b && j >= e)
	{
		tree[node].ff = v;
		if(b != e)
		{
			tree[node << 1].ss = v;
			tree[(node << 1) | 1].ss = v;
		}
		return;
	}
	int m = (b + e) >> 1;
	upd(node << 1, b, m, i, j, v);
	upd((node << 1) | 1, m + 1, e, i, j, v);
}

int qry(int node, int b, int e, int pos)
{
	if(pos > e || pos < b) return 0;
	if(tree[node].ss)
	{
		tree[node].ff = tree[node].ss;
		if(b != e)
		{
			tree[node << 1].ss = tree[node].ss;
			tree[(node << 1) | 1].ss = tree[node].ss;
		}
		tree[node].ss = 0;
	}
	if(b == e)
	{
		return tree[node].ff;
	}
	int m = (b + e) >> 1;
	return max(qry(node << 1, b, m, pos), qry((node << 1) | 1, m + 1, e, pos));
}

int main()
{
	int t = Int(), test = 1;
	while(t--)
	{
		memset(tree, 0, sizeof(tree));
		memset(cn, 0, sizeof(cn));
		int q = Int(), v = 1;
		int x = q;
		while(x--)
		{
			int x = Int(), y = Int();
			upd(1, 1, 2 * q, x, y, v++);
		}
		for(int i = 1; i <= 2 * q; i++)
		{
			int id = qry(1, 1, 2 * q, i);
			//cout << id << endl;
			cn[id]++;
		}
		int ans = 0;
		for(int i = 1; i < N; i++) if(cn[i]) ans++;
		printf("Case %d: %d\n", test++, ans);
	}
	return 0;
}
