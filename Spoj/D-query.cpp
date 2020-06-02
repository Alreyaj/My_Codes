#include<bits/stdc++.h>
using namespace std;

struct trr{
    int rt,lt,idx;
};

bool comp(trr a,trr b)
{
    if(a.rt<b.rt) return true;
    if(a.rt==b.rt) return a.lt<b.lt;
    return false;
}

int a[30009],tree[30009],pc[1000009],ans[200009];
trr qr[200009];

void upd(int n,int v)
{
    while(n<=30000)
    {
        tree[n]+=v;
        n+=(n&(-n));
    }
}

int qry(int n)
{
    int sm=0;
    while(n>0)
    {
        sm+=tree[n];
        n-=(n&(-n));
    }
    return sm;
}

int main()
{
    int n,q;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&qr[i].lt,&qr[i].rt);
        qr[i].idx = i;
    }
    sort(qr+1,qr+q+1,comp);
    int j=1;
    for(int i=1;i<=n;i++)
    {
        if(pc[a[i]])
        {
            upd(pc[a[i]],-1);
        }
        pc[a[i]] = i;
        upd(i,1);
        while(j<=q&&qr[j].rt==i)
        {
            ans[qr[j].idx] = qry(i) - qry(qr[j].lt-1);
            j++;
        }
    }
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
}
