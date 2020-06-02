#include<bits/stdc++.h>
using namespace std;


const int N=2*10e5+9;
int a[N];
long long ans;

int bn(int l,int r,int x)
{
    //cout<<l<<" "<<r<<endl;
    if(l>r) return r;
    int m=(l+r)/2;
    if(a[m]==x) return m-1;
    else if(a[m]<x&&a[m+1]>x) return m;
    else if(a[m]>x) return bn(l,m-1,x);
    else if(a[m+1]<=x) return bn(m+1,r,x);
}

void merge(int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergecnt(int l,int r)
{
    if(l>=r) return;
    int m=(l+r)/2;
    mergecnt(l,m);
    mergecnt(m+1,r);

    //for(int i=l;i<=r;i++) cout<<a[i]<<" ";
   // cout<<endl;
    for(int i=l,j=m+1;i<=m;i++)
    {
        j=bn(j,r,a[i]);
        //cout<<"T"<<i<<" "<<j<<endl;
        ans+=j-m;
        if(j<=m) j=m+1;
    }
    merge(l,m,r);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        a[n+1]=INT_MAX;
        ans=0;
        mergecnt(1,n);
        cout<<ans<<endl;

    }
}
