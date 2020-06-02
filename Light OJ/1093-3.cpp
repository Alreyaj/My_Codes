#include<bits/stdc++.h>
using namespace std;
#define N 100009

int a[N];
pair <int, int> tree[N * 4];

void build(int node, int b, int e)
{
    if(b == e)
    {
        tree[node].first = a[b];
        tree[node].second = a[b];
        return;
    }
    int l = node << 1;
    int m = (b + e) >> 1;
    build(l, b, m);
    build(l | 1, m + 1, e);
    tree[node].first = max(tree[l].first, tree[l | 1].first);
    tree[node].second = min(tree[l].second, tree[l | 1].second);
}

pair <int, int> qry(int node, int b, int e, int i, int j)
{
    if(i > e || j < b) return {0, INT_MAX};
    if(i <= b && j >= e) return tree[node];
    int l = node << 1;
    int m = (b + e) >> 1;
    pair <int, int> ff, ss;
    ff = qry(l, b, m, i, j);
    ss = qry(l | 1, m + 1, e, i, j);
    return {max(ff.first, ss.first), min(ff.second, ss.second)};
}

int main()
{
    int x, n, t, test = 1, k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        int ans = 0;
        deque<int> mx,mn;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        build(1, 1, n);
        for(int i = 1; i <= n - k + 1; i++)
        {
            pair <int, int> pr;
            pr = qry(1, 1, n, i, i + k - 1);
            ans = max(ans, abs(pr.first - pr.second));
        }
        printf("Case %d: %d\n", test++, ans);
    }
}


