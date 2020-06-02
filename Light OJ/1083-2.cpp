#include<bits/stdc++.h>
using namespace std;
#define N 30009
int a[N], tree[4*N], n;

void build(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = b;
        return;
    }
    int l = node << 1;
    int m = (b + e) >> 1;
    build(l, b, m);
    build(l | 1, m + 1, e);
    if(a[tree[l]] < a[tree[l | 1]]) tree[node] = tree[l];
    else tree[node] = tree[l | 1];
}

int qry(int node, int b, int e, int i, int j)
{
    if(i > e || j < b) return -1;
    if(i <= b && j >= e) return tree[node];
    int l = node << 1;
    int m = (b + e) >> 1;
    int ff = qry(l, b, m, i, j);
    int ss = qry(l | 1, m + 1, e, i, j);
    if(ff == -1) return ss;
    if(ss == -1) return ff;
    if(a[ff] < a[ss]) return ff;
    else return ss;
}

int solve(int b, int e)
{
    if(b > e) return 0;
    if(b == e) return a[b];
    int mn = qry(1, 1, n, b, e);
    //cout<<mn<<endl;
    int ans = a[mn] * (e - b + 1);
    ans = max(ans, solve(b, mn - 1));
    ans = max(ans, solve(mn + 1, e));
    return ans;
}

int main()
{
    int t, test = 1;
    scanf("%d", &t);
    while(t--)
    {
        memset(tree, 0, sizeof(tree));
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        build(1, 1, n);
        printf("Case %d: %d\n", test++, solve(1, n));
        //for(int i = 1; i <= 4*n; i++) cout << tree[i] << " ";
    }
}
