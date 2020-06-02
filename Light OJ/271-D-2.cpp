#include <bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;
#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define Max(a, b)      a > b ? a : b
#define Min(a, b)      a < b ? a : b
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)


const LL Mod = 1000000007;
const int N = 1500 + 5, P = 37;

ULL Pow[N];

int main() {
    Pow[0] = 1;
    for (int i = 1; i < N; i++) {
        Pow[i] = Pow[i - 1] * P;
    }
    set <ULL> good;
    string s, t;
    int k;
    cin >> s >> t >> k;

    for (int i = 0; s[i]; i++) {
        int bad = k;
        ULL has = 0;
        for (int j = i; s[j]; j++) {
            if (t[s[j] - 'a'] == '0') bad--;
            if (bad < 0) break;
            has = has + Pow[j - i] * s[j];
            good.insert(has);
        }
    }
    cout << good.size() << endl;
}
