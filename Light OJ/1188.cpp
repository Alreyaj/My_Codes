#include<bits/stdc++.h>
using namespace std;
#define N 100009
#define SN 350

int a[N], cn[N], res[N];
struct st{
    int l, r, id;
};

st pr[N];

bool cmp(st ff, st ss)
{
    if(ff.l / SN == ss.l / SN) return ff.r < ss.r;
    return ff.l / SN < ss.l / SN;
    return false;
}

int main()
{
    int t, test = 1, n, q;
    scanf("%d", &t);
    while(t--)
    {
        memset(cn, 0, sizeof(cn));
        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= q; i++)
        {
            scanf("%d %d", &pr[i].l, &pr[i].r);
            pr[i].id = i;
        }
        sort(pr + 1, pr + q + 1, cmp);
        int lc = 1, rc = 0, ans = 0;
        for(int i = 1; i <= q; i++)
        {
            int pl = pr[i].l;
            int rr = pr[i].r;
            while(lc < pl)
            {
                if(cn[a[lc]] == 1) ans--;
                cn[a[lc]]--;
                lc++;
            }
            while(lc > pl)
            {
                lc--;
                if(!cn[a[lc]]) ans++;
                cn[a[lc]]++;
            }
            while(rc < rr)
            {
                rc++;
                if(!cn[a[rc]]) ans++;
                cn[a[rc]]++;
            }
            while(rc > rr)
            {
                if(cn[a[rc]] == 1) ans--;
                cn[a[rc]]--;
                rc--;
            }
            res[pr[i].id] = ans;
        }
        printf("Case %d:\n", test++);
        for(int i = 1; i <= q; i++) printf("%d\n", res[i]);
    }
}

