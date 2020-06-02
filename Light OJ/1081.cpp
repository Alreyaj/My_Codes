#include<bits/stdc++.h>
using namespace std;
#define N 505

int a[N][N], st[N][N][25];

int main()
{
    int t, test = 1;
    scanf("%d", &t);
    while(t--)
    {
    	memset(st, 0, sizeof(st));
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                scanf("%d", &a[i][j]);
                st[i][j][0] = a[i][j];
            }
        }
        for(int k = 1; (1 << k) <= n; k++)
		{
			for(int i = 1; i + (1 << k) - 1 <= n; i++)
			{
				for(int j = 1; j + (1 << k) - 1 <= n; j++)
				{
                    int x = 1 << (k - 1);
                    st[i][j][k] = max({st[i][j][k - 1], st[i][j + x][k - 1], st[i + x][j][k - 1], st[i + x][j + x][k - 1]});
				}
			}
		}
		printf("Case %d:\n", test++);
		while(q--)
		{
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            int l = log2(z);
            int xx = 1 << l;
            int ans = max({st[x][y][l], st[x + z - xx][y][l], st[x][y + z - xx][l], st[x + z - xx][y + z - xx][l]});
            printf("%d\n", ans);
		}
    }
}
