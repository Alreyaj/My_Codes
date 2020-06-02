#include<bits/stdc++.h>
using namespace std;
const int mod = 100000007;

int dp[59][1009],a[51],b[51],n;

int cal(int i,int k)
{
    if(i>n)
    {
        if(k==0) return 1;
        else return 0;
    }
    if(dp[i][k]!=-1) return dp[i][k];
    int ans=0,cost=0;
    for(int j=0; j<=b[i]; j++)
    {
        if(k-cost>=0)
        {
            ans+=cal(i+1,k-cost)%mod;
            //cout<<i<<" "<<ans<<endl;
            cost+=a[i]%mod;
        }
        else break;
    }
    //ans+=cal(i+1,k)%mod;
    return dp[i][k] = ans%mod;
}


int main()
{
    int t,test = 0;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        int k;
        scanf("%d%d",&n,&k);
        for(int i=1; i<=n; i++) scanf("%d",&a[i]);
        for(int i=1; i<=n; i++) scanf("%d",&b[i]);
        printf("Case %d: %d\n",++test,cal(1,k));
    }
}
