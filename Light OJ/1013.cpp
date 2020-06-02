#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int dp[33][33];
long long dis[33][33][33];

int solve(int i, int j)
{
    if(i==s1.size()||j==s2.size()) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=0;
    if(s1[i]==s2[j])
    {
        ans = solve(i+1, j+1)+1;
    }
    else ans = max(solve(i+1, j),solve(i, j+1));
    return dp[i][j] = ans;
}

long long path(long long i,long long j,long long l)
{
    if(i==s1.size()&&j==s2.size()&&l==0) return 1;
    if(i==s1.size()&&j==s2.size()&&l!=0) return 0;
    if(i==s1.size()&&j!=s2.size()) return dis[i][j][l] = path(i,j+1,l-1);
    if(i!=s1.size()&&j==s2.size()) return dis[i][j][l] = path(i+1,j,l-1);
    if(dis[i][j][l]!=-1) return dis[i][j][l];
    long long ans;
    if(s1[i]==s2[j]) ans = path(i+1,j+1,l-1);
    else ans = path(i+1,j,l-1)+path(i,j+1,l-1);
    return dis[i][j][l] = ans;
}


int main()
{
    int t, test = 0;
    cin >> t;
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        memset(dis, -1, sizeof(dis));
        cin>>s1>>s2;
        int ans = (s1.size()+s2.size())-solve(0, 0);
        printf("Case %d: %d %lld\n", ++test, ans, path(0,0,(long long)ans));
    }
}

