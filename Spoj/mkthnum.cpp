#include<bits/stdc++.h>
using namespace std;
#define N 100009
#define ff first
#define ss second
#define all(x) x.begin(), x.end()


int a[N], cn[N];
vector<int>v[N * 4];
pair<int, int>pr[N];

void build(int node, int b, int e)
{
    if(b == e)
    {
        v[node].push_back(a[b]);
        return;
    }
    int l = node << 1;
    int m = (b + e) >> 1;
    build(l, b, m);
    build(l | 1, m + 1, e);
    merge(all(v[l]), all(v[l | 1]), back_inserter(v[node]));
}

int qry(int node, int b, int e, int i, int j, int x)
{
    if(i > e || j < b) return 0;
    if(i <= b && j >= e)
    {
        int pos = lower_bound(all(v[node]), x) - v[node].begin();
        return pos;
    }
    int l = node << 1;
    int m = (b + e) >> 1;
    return qry(l, b, m, i, j, x) + qry(l | 1, m + 1, e, i, j, x);
}
bool chk(int node, int b, int e, int i, int j, int x)
{
	if(i > e || j < b) return false;
	if(i <= b && j >= e)
    {
        int pos = lower_bound(all(v[node]), x) - v[node].begin();
        int hr = upper_bound(all(v[node]), x) - v[node].begin();
        if(pos == hr) return false;
        return true;
    }
    int l = node << 1;
    int m = (b + e) >> 1;
    return chk(l, b, m, i, j, x) | chk(l | 1, m + 1, e, i, j, x);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        pr[i] = {a[i], i};
    }
    sort(pr + 1, pr + 1 + n);
    int j = 1;
    cn[j] = pr[1].ff;
    a[pr[1].ss] = j;
    for(int i = 2; i <= n; i++)
    {
        if(pr[i].ff == pr[i - 1].ff)
        {
            a[pr[i].ss] = j;
        }
        else
        {
            j++;
            cn[j] = pr[i].ff;
            a[pr[i].ss] = j;
        }
    }
    //for(int i = 1; i <= n; i++) cout << a[i] << " ";
    build(1, 1, n);
    int x, y, val;
    while(m--)
    {
        scanf("%d %d %d", &x, &y, &val);
        int lf = 1, rt = n;
        while(lf <= rt)
		{
            int md = (lf + rt) >> 1;
            int co = qry(1, 1, n, x, y, md);
            if(chk(1, 1, n, x, y, md) && co == val - 1)
			{
				printf("%d\n", cn[md]);
				break;
			}
			if(co >= val) rt = md - 1;
			else lf = md + 1;

		}
        //cout << chk(1, 1, n, x, y, val) << endl;
        //cout << qry(1, 1, n, x, y, val) << endl;
    }
}
