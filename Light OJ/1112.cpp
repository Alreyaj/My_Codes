#include<bits/stdc++.h>
using namespace std;

const int N=100009;
int a[N],ans;
int tree[N*4];

void build_tree(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=a[b];
        return;
    }
    int l=node*2;
    int r=l+1;
    int m=(b+e)/2;
    build_tree(l,b,m);
    build_tree(r,m+1,e);
    tree[node]=tree[l]+tree[r];
}

void up1(int node,int i,int v,int b,int e)
{
    if(i<b||i>e)
        return;
    if(b==e)
    {
        if(v==0)
        {
            ans=tree[node];
            tree[node]=0;
        }
        else
            tree[node]+=v;
        return;
    }
    int l=node*2;
    int r=l+1;
    int m=(b+e)/2;
    up1(l,i,v,b,m);
    up1(r,i,v,m+1,e);
    tree[node]=tree[l]+tree[r];
}

int query(int node,int i,int j,int b,int e)
{
    if(i>e||j<b)
        return 0;
    if(i<=b&&j>=e)
        return tree[node];
    int l=node*2;
    int r=l+1;
    int m=(b+e)/2;
    return query(l,i,j,b,m)+query(r,i,j,m+1,e);
}

int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        build_tree(1,1,n);
        //for(int i=1; i<=n*4; i++) cout<<tree[i]<<" ";
        printf("Case %d:\n",test++);
        while(q--)
        {
            int x;
            scanf("%d",&x);
            if(x==1)
            {
                int y;
                scanf("%d",&y);
                up1(1,y+1,0,1,n);
                printf("%d\n",ans);
            }
            else
            {
                int y,z;
                scanf("%d%d",&y,&z);
                if(x==2)
                    up1(1,y+1,z,1,n);
                else
                    printf("%d\n",query(1,y+1,z+1,1,n));
            }
        }

    }
}
