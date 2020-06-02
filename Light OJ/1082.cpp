#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

const int N=100009;
int a[N];
int tree[N*4];

void build_tree(int node,int b,int e)
{
    if(b==e){
        tree[node]=a[b];
        return;
    }
    int l=node*2;
    int r=l+1;
    int m=(b+e)/2;
    build_tree(l,b,m);
    build_tree(r,m+1,e);
    tree[node]=min(tree[l],tree[r]);
}

int query(int node,int i,int j,int b,int e)
{
    if(i>e||j<b)
        return INT_MAX;
    if(i<=b&&j>=e)
        return tree[node];
    int l=node*2;
    int r=l+1;
    int m=(b+e)/2;
    return min(query(l,i,j,b,m),query(r,i,j,m+1,e));
}


int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        for(int i=1; i<=n; i++) scanf("%d",&a[i]);
        build_tree(1,1,n);
        //for(int i=1; i<=n*4; i++) cout<<tree[i]<<" ";
        printf("Case %d:\n",test++);
        while(q--)
        {
            int i,j;
            scanf("%d%d",&i,&j);
            printf("%d\n",query(1,i,j,1,n));
        }
    }
}
