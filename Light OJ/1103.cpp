#include<bits/stdc++.h>
using namespace std;
#define N 200009
#define ll long long

int tree[N];
pair<int, int>pr[N];

void upd(int n)
{
	while(n < N)
	{
		tree[n]++;
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
    	memset(tree, 0, sizeof(tree));
    	int n, m;
    	scanf("%d %d", &n, &m);
    	for(int i = 1; i <= n + m; i++)
		{
            int x, y;
            scanf("%d %d", &x, &y);
            pr[i] = {x, y};
		}
		sort(pr + 1, pr + 1 + n + m);
		long long ans = 0;
		for(int i = 1; i <= n + m; i++)
		{
			//cout << qry(pr[i].second - 1) << endl;
			ans +=(ll)( i - qry(pr[i].second - 1) - 1);
			upd(pr[i].second);
		}
		printf("Case %d: %lld\n", test++, ans);
    }
}
