#include<bits/stdc++.h>
using namespace std;
#define mod 100000007

int a[10009],res[10009];
int main()
{
    int t,test=0;
    cin>>t;
    while(t--)
    {
        memset(res,0,sizeof(res));
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++) scanf("%d",&a[i]);
        res[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=a[i];j<=m;j++)
            {
                res[j]=(res[j]+res[j-a[i]])%mod;
            }
        }
        printf("Case %d: %d\n",++test,res[m]);
    }
}
