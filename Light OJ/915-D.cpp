#include<bits/stdc++.h>
#define N 509
using namespace std;
vector<int>v[N];
int s[N],c=0,c2=0;
bool b[N];

void dfs(int i)
{
    if(b[i])
    {
        c++;
        //b[i]=false;
        return;
    }
    b[i]=true;
    int l=v[i].size();
    for(int j=0; j<l; j++)
        dfs(v[i][j]);
       // for(int j=l-1;)
}


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    for(int i=1; i<=n; i++) {
            if(!b[i])
            dfs(i);
    }
    cout<<c<<endl;
    if(c>1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}

