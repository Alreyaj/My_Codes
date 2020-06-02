#include<bits/stdc++.h>
using namespace std;
#define N 100009

struct st
{
    int c1,c2,c0,l;
};

st tree[4 * N];

void build(int node, int b, int e)
{
    if(b == e)
    {
        tree[node].c0 = 1;
        return;
    }
    int l = node << 1;
    int r = l | 1;
    int m = (b + e) >> 1;
    build(l, b, m);
    build(r, m + 1, e);
    tree[node].c0 = tree[l].c0 + tree[r].c0;
}

void upd(int node, int b, int e, int i, int j)
{
    int l = node << 1;
    int r = l | 1;
    if(tree[node].l)
    {
        int x = tree[node].l % 3;
        while(x--)
        {
            swap(tree[node].c1, tree[node].c2);
            swap(tree[node].c1, tree[node].c0);
        }
        if(b != e)
        {
            tree[l].l += tree[node].l;
            tree[r].l += tree[node].l;
        }
        tree[node].l = 0;
    }
    if(i > e || j < b) return;
    if(i <= b && j >= e)
    {
        swap(tree[node].c1, tree[node].c2);
        swap(tree[node].c1, tree[node].c0);
        if(b !=e )
        {
            tree[l].l++;
            tree[r].l++;
        }
        return;
    }
    int m = (b + e) >> 1;
    upd(l, b, m, i, j);
    upd(r, m + 1, e, i, j);
    tree[node].c0 = tree[l].c0 + tree[r].c0;
    tree[node].c1 = tree[l].c1 + tree[r].c1;
    tree[node].c2 = tree[l].c2 + tree[r].c2;
}

int qry(int node, int b, int e, int i, int j)
{
    int l = node << 1;
    int r = l | 1;
    if(i > e || j < b) return 0;
    if(tree[node].l)
    {
        int x = tree[node].l % 3;
        while(x--)
        {
            swap(tree[node].c1, tree[node].c2);
            swap(tree[node].c1, tree[node].c0);
        }
        if(b !=e )
        {
            tree[l].l += tree[node].l;
            tree[r].l += tree[node].l;
        }
        tree[node].l = 0;
    }
    if(i <= b && j >=e)
    {
        return tree[node].c0;
    }
    int m = (b + e) >> 1;
    return qry(l, b, m, i, j) + qry(r, m + 1, e, i, j);
}

int main()
{
    int t, test = 1, n, q, tp, x, y;
    scanf("%d", &t);
    while(t--)
    {
        for(int i = 1; i < 4 * N; i++)
        {
            tree[i] = {0, 0, 0, 0};
        }
        scanf("%d %d", &n, &q);
        printf("Case %d:\n", test++);
        build(1, 1, n);
        while(q--)
        {
            scanf("%d %d %d", &tp, &x, &y);
            x++, y++;
            if(tp)
            {
                printf("%d\n", qry(1, 1, n, x, y));
            }
            else
            {
                upd(1, 1, n, x, y);
            }
        }
    }
}
