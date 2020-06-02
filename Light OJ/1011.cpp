#include<bits/stdc++.h>
using namespace std;
int n, a[20][20], dp[20][1<<17];

int solve(int i, int bit)
{
    if(i>n) return 0;
    if(dp[i][bit]!=-1) return dp[i][bit];
    int ans=0;
    for(int j=1;j<=n;j++)
    {
        if(bit&(1<<j)) continue;
        ans = max(ans, solve(i+1, bit|(1<<j))+a[i][j]);
    }
    return dp[i][bit] = ans;
}

int main()
{
    int t, test = 0;
    cin >> t;
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> a[i][j];
        printf("Case %d: %d\n", ++test, solve(1, 0));
    }
}
