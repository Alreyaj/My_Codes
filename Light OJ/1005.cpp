///----------------------///
///---Code Written by----///
///-----Al-Shahreyaj-----///
///----------------------///
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define vin vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define pq priority_queue
#define all(x) x.begin(),x.end()
#define mod 10000007

int ini()
{
    int x;
    scanf("%d",&x);
    return x;
}
ll inl()
{
    ll x;
    scanf("%lld",&x);
    return x;
}

int n,k;
ll dp[35][35];

ll cal(int i,string s,int k)
{
    //cout<<s<<endl;
    if(i==0&&k==0) return 1LL;
    if(i==0&&k>0) return 0LL;
    if(dp[i][k]!=-1) return dp[i][k];
    ll ans = cal(i-1,s,k);
    if(k!=0)
    {
        for(int j=1; j<=n; j++)
        {
            if(s[j]=='0')
            {
                string ss = s;
                ss[j] = '1';
                ans+=cal(i-1,ss,k-1);
            }
        }
    }
    return dp[i][k] = ans;
}


int main()
{
    int t=ini(),test=0;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        cin>>n>>k;
        printf("Case %d: ",++test);
        if(k>n) printf("0\n");
        else
        {
            string s = "00000000000000000000000000000000000";
            printf("%lld\n", cal(n,s,k));
        }
    }
}

