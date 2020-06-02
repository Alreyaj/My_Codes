#include<bits/stdc++.h>
using namespace std;


const int N=2*10e5+9;
int a[N];
int B[10000009];

int cnt(int indx)
{
    int sum=0;
    //indx-=indx&(-indx);
    while(indx>0)
    {
        sum+=B[indx];
        indx-=indx&(-indx);

    }
    return sum;
}

void update(int indx,int n)
{
    while(indx<=n)
    {
        B[indx]++;
        indx+=indx&(-indx);
    }
}

int main()
{
    int t = 1;
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mx=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            mx=max(a[i],mx);
        }
        for(int i=1;i<=mx;i++) B[i]=0;
        long long ans=0;
        for(int i=n;i>0;i--)
        {
            ans+=cnt(a[i]-1);

            update(a[i],mx);
            //for(int i=1;i<=mx;i++) cout<<B[i]<<" ";
            //cout<<endl;
        }
        printf("%lld\n",ans);
    }
}
