#include<bits/stdc++.h>
using namespace std;
#define N 2009
#define ff first
#define ss second

string s[N];
int a[N][N];

int main()
{
    int t, test = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, m, ans = 0;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++) cin >> s[i];
        for(int i = 0; i < n; i++)
        {
            stack<pair<int, int > > st;
            for(int j = 0; j < m; j++)
            {
                a[i][j] = (i == 0 ? 0 : a[i - 1][j]) + (s[i][j] == '0'? 1 : 0);
                //cout << a[i][j] << " ";
                if(s[i][j] == '0')
                {
                	int y = j;
                    while(!st.empty() && st.top().ff > a[i][j])
                    {
                        int x = st.top().ff;
                        y = st.top().ss;
                        st.pop();
                        ans = max(ans, (j - y) * x);
                    }
                    st.push({a[i][j], y});
                }
                else
                {
                	a[i][j] = 0;
                    while(!st.empty())
                    {
                        int x = st.top().ff;
                        int y = st.top().ss;
                        st.pop();
                        ans = max(ans, (j - y) * x);
                    }
                }
            }
            while(!st.empty())
            {
                int x = st.top().ff;
                int y = st.top().ss;
                st.pop();
                ans = max(ans, (m - y) * x);
            }
            //cout << endl;
        }
        printf("Case %d: %d\n", test++, ans);
    }
}
