#include<bits/stdc++.h>
using namespace std;
#define N 100009
#define ll long long
#define mod 1000000009
vector<pair<ll, ll> > v1, v2, v3;
vector<ll>prime;
bool b[100000];
void gen()
{
    ll l = (ll)sqrt(1000000000) + 2;
    for(ll i = 2; i <= 1000; i++)
    {
        if(!b[i])
        {
            prime.push_back(i);
            for(ll j = i * i; j <= l; j += i) b[j] = true;
        }
    }
    for(ll i = 1001; i <= l; i++) if(!b[i]) prime.push_back(i);
}

ll bigmod ( ll a, ll p)
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
    gen();
    //cout << sqrt(1000000000) + 2 <<endl;
    //cout<< prime.size() << endl;
    ll n;
    ll x;
    scanf("%lld %lld", &n, &x);
    ll p_l = prime.size();
    for(ll k = 0; k < p_l; k++)
    {
        ll j = prime[k];
        if(j * j > x) break;
        if(x % j == 0)
        {
            ll c = 0;
            while(x % j == 0)
            {
                c++;
                x /= j;
            }
            v1.push_back({j, c});
        }
    }
    if(x > 1) v1.push_back({x, 1});
    ll ans = 1;
    for(ll i = 2; i <= n; i++)
    {
        scanf("%lld", &x);
        for(ll k = 0; k < p_l; k++)
        {
            ll j = prime[k];
            if(j * j > x) break;
            if(x % j == 0)
            {
                ll c = 0;
                while(x % j == 0)
                {
                    c++;
                    x /= j;
                }
                v2.push_back({j, c});
            }
        }
        if(x > 1) v2.push_back({x, 1});
        ll l1 = 0, l2 = 0;
        while(l1 != v1.size() || l2 != v2.size())
        {
            if(l1 == v1.size()) v3.push_back(v2[l2++]);
            else if(l2 == v2.size()) v3.push_back(v1[l1++]);
            else
            {
                if(v1[l1].first == v2[l2].first)
                {
                    ans = (ans * bigmod(v1[l1].first, min(v1[l1].second, v2[l2].second))) % mod;
                    v3.push_back({v1[l1].first, max(v1[l1].second, v2[l2].second)});
                    l1++;
                    l2++;
                }
                else if(v1[l1] > v2[l2])
                {
                    v3.push_back(v2[l2]);
                    l2++;
                }
                else
                {
                    v3.push_back(v1[l1]);
                    l1++;
                }
            }
        }
        //for(int x:v3) cout<<x<<endl;
        v1 = v3;
        v2.clear();
        v3.clear();
    }
    printf("%lld\n", ans);
}
