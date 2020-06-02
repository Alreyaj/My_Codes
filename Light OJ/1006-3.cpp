#include<bits/stdc++.h>
using namespace std;
const int mod=10000007;

int a[10009];

int solve(int n)
{
    if(a[n]!=-1) return a[n]%mod;
    return a[n]=(solve(n-1)+solve(n-2)+solve(n-3)+solve(n-4)+solve(n-5)+solve(n-6))%mod;
}
int main()
{
    int t,test=0;
    cin>>t;
    while(t--)
    {
        memset(a,-1,sizeof(a));
        for(int i=0;i<6;i++)  scanf("%d",&a[i]);
        int n;
        scanf("%d",&n);
        printf("Case %d: %d\n",++test,solve(n)%mod);
    }
}

