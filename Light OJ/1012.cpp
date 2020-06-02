#include<bits/stdc++.h>
using namespace std;
int ans;
string s[25];
bool b[25][25];

void dfs(int i,int j,int r,int c)
{
    if(i<0||i>=r) return;
    if(j<0||j>=c) return;
    if(b[i][j]) return;
    b[i][j]=true;
    ans++;
    dfs(i+1,j,r,c);
    dfs(i-1,j,r,c);
    dfs(i,j+1,r,c);
    dfs(i,j-1,r,c);
}

int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        ans=0;
        int c,r,px,py;
        cin>>c>>r;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++) b[i][j]=false;
        }
        for(int i=0;i<r;i++) cin>>s[i];
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(s[i][j]=='@')
                {
                    px=i;py=j;
                }
                else if(s[i][j]=='#') b[i][j]=true;
            }
        }
        dfs(px,py,r,c);
        printf("Case %d: %d\n",test++,ans);
    }
}
