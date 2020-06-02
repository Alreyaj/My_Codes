#include<bits/stdc++.h>
using namespace std;
const int N=100009;

int a[N];

int bl(int l,int r,int x)
{
    int m=(l+r)/2;
    if(x<=a[m]&&x>a[m-1]) return m;
    else if(l>r) return -9999;
    else if(x<=a[m-1]) return bl(l,m-1,x);
    else if(x>a[m]) return bl(m+1,r,x);
}
int br(int l,int r,int x)
{
    int m=(l+r)/2;
    if(x>=a[m]&&x<a[m+1]) return m;
    else if(l>r) return -1;
    else if(x<a[m]) return br(l,m-1,x);
    else if(x>=a[m+1]) return br(m+1,r,x);
}

int main()
{
    int t,test=1,n,q,l,r;
    scanf("%d",&t);
    while(t--)
    {
        a[0]=-1;
        scanf("%d%d",&n,&q);
        a[n+1]=INT_MAX;;
        for(int i=1; i<=n; i++) scanf("%d",&a[i]);
        printf("Case %d:\n",test++);
        while(q--)
        {
            scanf("%d%d",&l,&r);
            printf("%d\n",(br(0,n,r)-bl(1,n+1,l)+1));

        }
    }
}

