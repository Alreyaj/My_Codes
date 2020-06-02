#include<bits/stdc++.h>
using namespace std;
#define N 100009

int a[N];

int main()
{
    int x, n, t, test = 1, k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        int ans = 0;
        deque<int> mx,mn;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if(i != 1) ans = max(ans, abs(a[mx.front()] - a[mn.front()]));
            while(!mx.empty() && a[mx.back()] <= a[i]) mx.pop_back();
            while(!mn.empty() && a[mn.back()] >= a[i]) mn.pop_back();
            mx.push_back(i);
            mn.push_back(i);
            while(!mx.empty() && mx.front() <= i - k) mx.pop_front();
            while(!mn.empty() && mn.front() <= i - k) mn.pop_front();
        }
        printf("Case %d: %d\n", test++, ans);
    }
}

