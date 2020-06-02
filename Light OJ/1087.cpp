#include<bits/stdc++.h>
using namespace std;
#define N 200009

int a[N], tree[4 * N];
bool b[N];

void build(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = a[b]? 1 : 0;
        return;
    }
    int l = node << 1;
    int m = (b + e) >> 1;
    build(l, b, m);
    build(l | 1, m + 1, e);
    tree[node] = tree[l] + tree[l | 1];
}

void update(int node, int b, int e, int pos, int v)
{
    if(pos > e || pos < b) return;
    if(b == e)
    {
        tree[node] = v;
        return;
    }
    int l = node << 1;
    int m = (b + e) >> 1;
    update(l, b, m, pos, v);
    update(l | 1, m + 1, e, pos, v);
    tree[node] = tree[l] + tree[l | 1];
}

int qry(int node, int b, int e, int i, int j)
{
    if(i > e || j < b) return 0;
    if(i <= b && j >= e) return tree[node];
    int l = node << 1;
    int m = (b + e) >> 1;
    return qry(l, b, m, i, j) + qry(l | 1, m + 1, e, i, j);
}

int main()
{
    int t, test = 1;
    scanf("%d", &t);
    while(t--)
    {
        printf("Case %d:\n", test++);
        memset(tree, 0, sizeof(tree));
        memset(b, false, sizeof(b));
        int n, q, x;
        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            b[i] = true;
        }
        build(1, 1, N-1);
        int lc = n;
        while(q--)
        {
            char c;
            scanf(" %c %d", &c, &x);
            if(c == 'a')
            {
                ++lc;
                a[lc] = x;
                b[lc] = true;
                update(1, 1, N-1, lc, 1);
            }
            else
            {
                int l = 1, r = 200000;
                bool bb = false;
                while(l <= r)
                {
                    int m = (l + r) >> 1;
                    int res = qry(1, 1, N-1, 1, m);
                    if(res == x && b[m])
                    {
                        printf("%d\n", a[m]);
                        b[m] = false;
                        update(1, 1, N-1, m, 0);
                        bb = true;
                        break;
                    }
                    else if(res > x) r = m - 1;
                    else if(res == x && !b[m]) r = m - 1;
                    else l = m + 1;
                }
                if(!bb) printf("none\n");
            }
        }

    }
}
