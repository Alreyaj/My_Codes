#include<bits/stdc++.h>
using namespace std;
#define N 1430000

int tree[4 * N];

void build(int node, int b, int e)
{
    if(b == e)
    {
        if(b & 1) tree[node] = 1;
        else tree[node] = 0;
        return;
    }
    int l = node << 1;
    int r = l | 1;
    int m = (b + e) >> 1;
    build(l, b, m);
    build(r, m + 1, e);
    tree[node] = tree[l] + tree[r];
}

int qry(int node, int b, int e, int pos)
{
    if(b == e)
    {
        return b;
    }
    int l = node << 1;
    int r = l | 1;
    int m = (b + e) >> 1;
    if(tree[l] >= pos) return qry(l, b, m, pos);
    else return qry(r, m + 1, e, pos - tree[l]);
}

void upd(int node, int b, int e, int pos)
{
    if(b == e)
    {
        tree[node] = 0;
        return;
    }
    int l = node << 1;
    int r = l | 1;
    int m = (b + e) >> 1;
    if(tree[l] >= pos) upd(l, b, m, pos);
    else  upd(r, m + 1, e, pos - tree[l]);
    tree[node] = tree[l] + tree[r];
}

int main()
{
    int t, n, test = 1;
    scanf("%d", &t);
    build(1, 1, N-1);
    //for(int i = 1; i <= 4 * N; i++) cout << tree[i] << " ";
    for(int i = 2; i <= 100000; i++)
    {
        int x = qry(1, 1, N - 1, i);
        //cout << x << endl;
        int y = x;
        while(y < N)
        {
            upd(1, 1, N - 1, y);
            y += x;
            y--;
        }
        //cout << x << endl;
    }
    while(t--)
    {
        scanf("%d", &n);
        printf("Case %d: %d\n", test++, qry(1, 1, N - 1, n));
    }
}

