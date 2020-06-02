/**********************************************************************\
|           _______  _     _____    ____   ___     _                   |
|          |___   _|(_)   / ___/   / _  | |   \   | |                  |
|              | |  | |  / /___   / /_| | | |\ \  | |                  |
|           _  | |  | | /___  /  /  __  | | | \ \ | |                  |
|           \ \| |  | | ___/ /  / /   | | | |  \ \| |                  |
|            \___/  |_|/____/  /_/    |_| |_|   \___|                  |
|                  Computer Science and Engineering                    |
|  Bangabandhu Sheikh Mujibur Rahman Science and Technology University |
|         devskill:jisancse||uva:jishan047||github:jisan047            |
\**********************************************************************/

                /********************\
                |                    |
                |    lets try.....   |
                |                    |
                \********************/

#include<bits/stdc++.h>
using namespace std;

///pre-processing
#define     gcd(a, b)       __gcd(a,b)
#define     lcm(a, b)       (a * b) / gcd(a, b)
#define     loop(i, n)      for(int i=0;i<n;i++)
#define     all(x)          x.begin(),x.end()
#define     mem(a, x)       memset(a,x,sizeof a)
#define     endl            '\n'
#define     ss              second
#define     ff              first
#define     TN              typename
#define     set(a, x)       (a |= (1 << x));

///input functions
int Int(){int x;scanf("%d",&x);return x;}
long long Long(){long long x;scanf("%lld",&x);return x;}
double Double(){double x;scanf("%lf",&x);return x;}

///input functions shorting
#define Int Int()
#define Long Long()
#define Double Double()
#define Float Float()

///Constants
const int N = 31624;
const long long MOD = (long long) 1e9 + 9LL;

///BitMask
int Set(int a, int x){return (a |= (1 << x));}
int Reset(int a, int x){return (a &= ~(1 << x));}
bool Isset(int a, int x){return (bool) (a & (1 << x));}

//Trying to do something.
//()()()()()()()()() ..... ()()()()()()()()()()()()
//~~~~~~~~~~~~~~~~~~~~~~Get Ready~~~~~~~~~~~~~~~~~~~~~

///debugger

///end

// loading..................
int total[N];
int needed[N];
int mark[N];
long long bigmod (long long a, long long p, long long m){
    long long res = 1LL;
    long long x = a;
    while(p){
        if (p & 1LL){
            res = (res * x) % m;
        }
        x = (x * x) % m;
        p = p >> 1LL;
    }
    return res % MOD;
}

int main()
{
    //freopen("input.txt","r",stdin);
    int n = Int;
    vector<int> primes;
    int limit = (int) sqrtl(N);
    mark[1] = 1;
    primes.push_back(2);
    for(int i = 4; i < N; i += 2){
        mark[i] = 1;
    }
    for(int i = 3; i < N; i += 2){
        if(!mark[i]){
            if(i <= 31623)
                primes.push_back(i);
            if(i <= limit){
                for(int j = i * i; j < N; j += (i * 2))mark[j] = 1;
            }
        }
    }
    int lm = primes.size();
    cout << lm << endl;
    priority_queue<int> extra;
    long long ans = 1LL;
    for(int i = 0; i < n; i++){
        int x = Int;
        for(int j = 0; j < lm; j++){
            if(x < primes[j])break;
            int cnt = 0;
            while(!(x % primes[j])){
                cnt++;
                x /= primes[j];
            }
            total[primes[j]] += cnt;
            needed[primes[j]] = max(needed[primes[j]], cnt);
        }
        if(x > 1){
            extra.push(x);
        }
    }
    for(int i = 0; i < lm; i++){
        long long now = bigmod(primes[i] * 1LL, (total[primes[i]] - needed[primes[i]]) * 1LL, MOD);
        ans = (ans * now) % MOD;
    }
    while(extra.size()){
        int j = extra.top();
        // cout << j << endl;
        extra.pop();
        while(j == extra.top() and extra.size()){
            extra.pop();
            ans = (ans * j) % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
