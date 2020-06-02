#include<bits/stdc++.h>
using namespace std;
#define N 100009
#define pii pair <int, int>
int a[N];
pii table[(int)log2(N) + 1][N];

void build(int n)
{
    for(int i = 1; i <= n; i++) table[0][i] = {a[i], a[i]};
    for(int i = 1; (1 << i) <= n; i++)
    {
        for(int j = 1; j + (1 << i) - 1 <= n; j++)
        {
            table[i][j] = {max(table[i - 1][j].first, table[i - 1][j + (1 << (i - 1))].first),
             min(table[i - 1][j].second, table[i - 1][j + (1 << (i - 1))].second)};
        }
    }
}

pii qry(int l, int r)
{
    int lg = log2(r - l + 1);
    return {max(table[lg][l].first, table[lg][r - (1 << lg) + 1].first), min(table[lg][l].second, table[lg][r - (1 << lg) + 1].second)};
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
        build(n);
        for(int i = 1; i <= n - k + 1; i++)
        {
            pii pr = qry(i, i + k - 1);
            ans = max(ans, abs(pr.first - pr.second));
        }
        printf("Case %d: %d\n", test++, ans);
    }
}

