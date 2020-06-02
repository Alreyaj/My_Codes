#include<bits/stdc++.h>
using namespace std;

int a[100009];
const int N = (int) 1e5 + 5;
int b[N];

void update(int in,int x)
{
    while(in<=N)
    {
        a[in]+=x;
        in+=in&(-in);
    }
}

int quary(int in)
{
    int ans=0;
    while(in>0)
    {
        ans+=a[in];
        in-=in & (-in);
    }
    return ans;
}


int main()
{
    int t,test=1;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1;i<=N;i++)
        {
            a[i]=0;
            b[i]=0;
        }
        printf("Case %d:\n",test++);
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            b[i] = x;
            update(i,x);
        }
        while(q--)
        {
            int c,i,j;
            scanf("%d",&c);
            if(c==1)
            {
                scanf("%d",&i);
                i++;
                printf("%d\n",b[i]);
                update(i,-b[i]);
                b[i] = 0;
            }
            else
            {
                scanf("%d%d",&i,&j);
                i++;
                if(c==2) {
                        update(i,j);
                        b[i]+=j;
                }
                else printf("%d\n",quary(j + 1)-quary(i - 1));
            }
        }
    }
}
