#include<bits/stdc++.h>
using namespace std;
#define N 1430000
bool b[N];
int tree[N];
vector<int>vv;

void upd(int n, int v)
{
    while(n < N)
    {
        tree[n] += v;
        n += (n & (-n));
    }
}

int qry(int n)
{
    int res = 0;
    while(n > 0)
    {
        res += tree[n];
        n -= (n & (-n));
    }
    return res;
}

int main()
{
    int t, n, test = 1;
    scanf("%d", &t);
    for(int i = 1; i < N; i++)
    {
        upd(i, 1);
    }
    //cout << qry(1) << endl;
    int x = 2, iv = 2;
    while(x < N)
    {
        int y = x;
        int z = x;
        vector<int>v;
        while(y < N)
        {
            int l = 1, r = N - 1;
            while(l <= r)
            {
                int m = (l + r) >> 1;
                int pos = qry(m);
                if(pos == y && !b[m])
                {
                    //cout << m <<endl;
                    b[m] = true;
                    v.push_back(m);
                    //upd(m, -1);
                    break;
                }
                else if(pos == y && b[m]) r = m - 1;
                else if(pos > y) r = m - 1;
                else l = m + 1;
            }
            y += x;
        }
        int ll = v.size();
        for(int i = 0; i < ll; i++)
        {
            upd(v[i], -1);
        }
        int l = 1, r = N - 1;
        bool bb = true;
        while(l <= r)
        {
            int m = (l + r) >> 1;
            int pos = qry(m);
            if(pos == iv && !b[m])
            {
                bb = false;
                //cout << m << endl;
                x = m;
                break;
            }
            else if(pos == iv && b[m]) r = m - 1;
            else if(pos > iv) r = m - 1;
            else l = m + 1;
        }
        if(bb) break;
        iv++;
        //x += 1;
        //cout << x << endl;
    }
    for(int i = 1; i < N; i++)
    {
        if(!b[i]) vv.push_back(i);
    }
    //cout << vv[100000-1] << endl;
    //for(int x:vv) cout << x << " ";
    while(t--)
    {
        scanf("%d", &n);
        printf("Case %d: %d\n", test++, vv[n-1]);
    }
}
