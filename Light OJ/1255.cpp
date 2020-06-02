#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll unsigned long long
const int N = 1000009;

ll hashval[N];
ll pw[N];
ll p = 131;

ll gethash(int l,int r)
{
    return ((hashval[r]-hashval[l-1])+mod)%mod;
}

int main()
{
    int t, ts = 1;
    scanf("%d", &t);
    while(t--)
    {
        //ios::sync_with_stdio(0), cin.tie(0);
        string s, ss;
        cin >> s >> ss;
        int n = s.size();
        int m = ss.size();
        pw[0] = 1 % mod;
        ll hash2 = 0LL;
        for(int i = 0; s[i]; i++)
        {
            hashval[i+1]=(hashval[i]+((s[i] - 'a' +1)*pw[i]))%mod;
            pw[i+1]=(pw[i]*p)%mod;
        }
        for(int i = 0; ss[i]; i++) hash2 =(hash2 +((ss[i] - 'a' + 1)*pw[i]))%mod;
        ll ans = 0;
        for(int i = 1; i <= n - m + 1; i++)
        {
            if((gethash(i, i + m - 1)) % mod == (hash2 * pw[i - 1]) % mod) ans++;
        }
        printf("Case %d: %lld\n", ts++, ans);
    }
}

