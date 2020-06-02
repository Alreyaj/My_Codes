#include<bits/stdc++.h>
using namespace std;

int a[209][209],n,dp[209][209];

int cal(int i,int j)
{
    if(i==2*n) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int res = 0;
    if(i<n) res = max(res,cal(i+1,j));
    if(i>=n && j<=(2*n-i)-1) res = max(res,cal(i+1,j));
    if(i<n && j<=i) res = max(res,cal(i+1,j+1));
    if(i>=n && j>1) res = max(res,cal(i+1,j-1));
    //cout<<i<<" "<<j<<endl;
    return dp[i][j] = res+a[i][j];
}

int main()
{
    int t,test = 1;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int i=1; i<2*n; i++) for(int j=1; j<=(i<=n?i:2*n-i); j++) scanf("%d",&a[i][j]);
        printf("Case %d: ",test++);
        cout<<cal(1,1)<<endl;
    }
}
