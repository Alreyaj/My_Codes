#include<bits/stdc++.h>
using namespace std;
#define N 100009
#define ff first
#define ss second
#define pii pair<int,int>
#define mod 1000000007
#define ll long long
ll a[N],cn[N],tree[N];
pair<ll,int>pr[N];

bool comp(pii x, pii y)
{
	if(x.ff<y.ff) return true;
	if(x.ff==y.ff) return x.ss<y.ss;
	return false;
}

void upd(int n,ll v)
{
	while(n<N)
	{
		tree[n]=(tree[n]+v)%mod;
		n+=(n&(-n));
	}
}

int qry(int n)
{
	ll ans = 0;
	while(n>0)
	{
		ans=(ans+tree[n])%mod;
		n-=(n&(-n));
	}
	return ans;
}

int main()
{
    int t,test=1,n;
    scanf("%d",&t);
    while(t--)
	{
		for(int i=1;i<N;i++) tree[i] = 0;
		//memset(tree,0,sizeof(tree));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			pr[i] = {a[i],i};
		}
		sort(pr+1,pr+n+1);
		ll ans=0,c=0;
		pr[0].ff = INT_MIN;
		//cout<<pr[0].ff<<endl;
		for(int i = 1; i <= n; i++)
		{
			int idx = pr[i].ss;
			//else
			//{
				//cout<<i<<" "<<qry(pr[i].ss)<<endl;
			cn[i]=(qry(idx)+1)%mod;
			if(pr[i].ff==pr[i-1].ff) {
					cn[i]-=c;
					c=(c+cn[i])%mod;
			}
			else c = cn[i];
			//}
			upd(pr[i].ss,cn[i]);
			//ps[i] = (ps[i-1]+cn[i])%mod;
			//cout<<i<<endl;
			ans=(ans+cn[i])%mod;
			//cout<<ans<<endl;
		}
		printf("Case %d: %lld\n",test++,ans);
	}
}
