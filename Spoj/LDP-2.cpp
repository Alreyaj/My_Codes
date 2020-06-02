#include<bits/stdc++.h>
using namespace std;
#define N 100009
#define ll long long
#define mod 1000000009

int a[N];
vector<int>prime;
bool b[N];
void gen(int n)
{
    int l = (int)sqrt(n) + 2;
    for(int i = 2; i <= 1000; i++)
    {
        if(!b[i])
        {
            prime.push_back(i);
            for(int j = i * i; j <= l; j += i) b[j] = true;
        }
    }
    for(int i = 1001; i <= l; i++) if(!b[i]) prime.push_back(i);
}

int bigmod ( int a, int p)
{
    if ( p == 0 )return 1; // If power is 0 ( a ^ 0 ), return 1

    if ( p & 1 ) // If power is odd
    {
        return ( 1LL * ( a % mod ) * ( bigmod ( a, p - 1) ) ) % mod;
    }
    else
    {
        long long tmp = bigmod ( a, p / 2);
        return ( tmp * tmp ) % mod;
    }
}

int main()
{
    int n;
    int x, mx = 0;
    ll ans = 1;
    scanf("%d", &n);
    for(int i = 1; i<= n; i++) scanf("%d", &a[i]), mx = max(mx, a[i]);
    gen(mx);
    int p_l = prime.size();
    //cout << p_l << endl;
    for(int k = 0; k < p_l; k++)
    {
        x = prime[k];
        int r = 0;
        for(int i = 1; i <= n; i++)
        {
            int c = 0;
            while(a[i] % x == 0)
            {
                c++;
                a[i] /= x;
            }
            ans = (ans * bigmod(x, min(r, c))) % mod;
            r = max(r, c);
        }
    }
    priority_queue<int> extra;
    for(int i = 1; i < n; i++)
    {
        if(a[i] > 1) extra.push(a[i]);
    }
    while(extra.size()){
        int j = extra.top();
        extra.pop();
        while(j == extra.top() and extra.size()){
            extra.pop();
            ans = (ans * j) % mod;
        }
    }
    printf("%lld\n", ans);
}
