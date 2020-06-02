#include<bits/stdc++.h>
using namespace std;

const int N=100009;

char s[N];
int tree[N*4],ans;


void build(int node,int b,int e)
{
    if(b==e){
        tree[node]=s[b]-'0';
        return;
    }
    else
    {
        tree[node]=0;
        int l=node*2;
        int r=node*2+1;
        int m=(b+e)/2;
        build(l,b,m);
        build(r,m+1,e);
    }
    return;
}

void update(int node,int i,int j,int b,int e)
{
    if(i>e||j<b)
        return;
    if(b>=i&&e<=j){
        tree[node]=tree[node]^1;
        return;
    }
    else
    {
        int l=node*2;
        int r=node*2+1;
        int m=(b+e)/2;
        update(l,i,j,b,m);
        update(r,i,j,m+1,e);
    }
    return;
}
void qry(int node,int i,int c,int b,int e)
{
    if(i<b||i>e)
        return;
    if(b==e)
    {
        ans=tree[node];
        //cout<<node<<endl;
        if(c%2==1)
            ans=ans^1;
        return;
    }
    int l=node*2;
    int r=node*2+1;
    int m=(b+e)/2;
    c+=tree[node];
    qry(l,i,c,b,m);
    qry(r,i,c,m+1,e);
}

int main()
{
    int t,test=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int l=strlen(s);
        build(1,0,l-1);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",test++);
        while(q--)
        {
            char c;
            scanf(" %c",&c);
            if(c=='I')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                update(1,x,y,1,l);
            }
            else
            {
                int x,c=0;
                scanf("%d",&x);
                qry(1,x,c,1,l);
                printf("%d\n",ans);
            }
        }
    }

}
