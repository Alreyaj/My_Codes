#include<bits/stdc++.h>
using namespace std;

stack < pair < int, int > > st;

int main()
{
    int t, n, x, test = 1;
    scanf("%d", &t);
    while(t--)
    {
        int ans = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
        {
            int y, idx = i;
            scanf("%d", &x);
            while(!st.empty() && st.top().first > x)
            {
                y = st.top().first;
                idx = st.top().second;
                st.pop();
                ans = max(ans, (i - idx)*y);
            }
            st.push({x, idx});
        }
        while(!st.empty())
        {
            int y = st.top().first;
            int idx = st.top().second;
            st.pop();
            ans = max(ans, (n + 1 - idx)*y);
        }
        printf("Case %d: %d\n", test++, ans);
    }
}
