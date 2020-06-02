#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, k;
    cin >> n >> k;
    ll x = (k - 1) * k;
    if(n > x) return cout << "NO" << "\n", 0;
    cout << "YES" << "\n";
    int i = 1, j = 1;
    for(int i = 1; i < k; i++)
    {
        for(int j = i + 1; j <= k; j++)
        {
            cout << i << " " << j << "\n";
            n--;
            if(!n) break;
            cout << j << " " << i << "\n";
            n--;
            if(!n) break;
        }
        if(!n) break;
    }
}
