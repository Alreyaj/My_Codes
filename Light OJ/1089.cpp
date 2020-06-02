#include<bits/stdc++.h>
using namespace std;
#define N 200009

int tree[N], a[N];
pair <int, int>pr[N];
vector<int>v;
map<int,int>mp;


int main()
{
    int t, n, q, x, y, test = 1;
    scanf("%d", &t);
    while(t--)
    {
        memset(tree, 0, sizeof(tree));
        v.clear();
        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d %d", &x, &y);
            x++, y++;
            pr[i] = {x, y};
            v.push_back(x);
            v.push_back(y);
        }
        for(int i = 1; i <= q; i++)
        {
            scanf("%d", &a[i]);
            v.push_back(++a[i]);
        }
        sort(v.begin(),v.end());
        x = 1;
        for(int i = 0; i < v.size(); i++)
        {
            if(!i) mp[v[i]] = x;
            else
            {
                if(v[i] == v[i - 1]) continue;
                else mp[v[i]] = ++x;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            pr[i] = {mp[pr[i].first], mp[pr[i].second]};
            tree[pr[i].first]++;
            tree[pr[i].second + 1]--;
        }
        for(int i = 1; i < N; i++) tree[i] += tree[i - 1];
        printf("Case %d:\n", test++);
        for(int i = 1; i <= q; i++)
        {
            a[i] = mp[a[i]];
            printf("%d\n", tree[a[i]]);
        }
    }
}
