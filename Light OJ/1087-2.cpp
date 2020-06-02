#include<bits/stdc++.h>
using namespace std;
#define N 200009

int a[N], tree[N];
bool b[N];

void update(int n, int v)
{
    while(n < N)
    {
        tree[n] += v;
        n += (n & (-n));
    }
}

int qry(int n)
{
    int res = 0;
    while(n > 0)
    {
        res += tree[n];
        n -= (n & (-n));
    }
    return res;
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
            update(i, 1);
            b[i] = true;
        }
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
                update(lc, 1);
            }
            else
            {
                int l = 1, r = 200000;
                bool bb = false;
                while(l <= r)
                {
                    int m = (l + r) >> 1;
                    int res = qry(m);
                    if(res == x && b[m])
                    {
                        printf("%d\n", a[m]);
                        b[m] = false;
                        update(m, -1);
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
