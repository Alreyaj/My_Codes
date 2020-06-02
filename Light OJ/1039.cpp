#include<bits/stdc++.h>
using namespace std;
//string f[55];
map<string,bool>mp;
map<string,int>dis;

void bfs(string s,string ans)
{
    int c=0;
    queue<string>q;
    q.push(s);
    dis[s]=0;
    while(!q.empty())
    {
        string ss=q.front();
        mp[ss]=true;
        q.pop();
        string ns=ss;
        for(int i=0; i<3; i++)
        {
            ns=ss;
            ns[i]=ns[i]+1;
            if(ns[i]<'a') ns[i]='z';
            else if(ns[i]>'z') ns[i]='a';
            //if(c++>10) return;
            if(!mp[ns])
            {
                mp[ns]=true;
                //cout<<ns<<endl;
                dis[ns]=dis[ss]+1;
                q.push(ns);
            }
            ns=ss;
            ns[i]=ns[i]-1;
            if(ns[i]<'a') ns[i]='z';
            else if(ns[i]>'z') ns[i]='a';
            if(!mp[ns])
            {
                mp[ns]=true;
                dis[ns]=dis[ss]+1;
                q.push(ns);
            }
        }
    }
}

int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        mp.clear();
        dis.clear();
        string s,e;
        cin>>s>>e;
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            string x,y,z;
            cin>>x>>y>>z;
            for(int j=0; j<x.size(); j++)
            {
                for(int k=0; k<y.size(); k++)
                {
                    for(int l=0; l<z.size(); l++)
                    {
                        string ss="   ";
                        ss[0]=x[j];
                        ss[1]=y[k];
                        ss[2]=z[l];
                        mp[ss]=true;
                    }
                }
            }
        }
        printf("Case %d: ",test++);
        if(mp[s]==true||mp[e]==true)
        {
            printf("-1\n");
            continue;
        }
        bfs(s,e);
        if(!mp[e]) printf("-1\n");
        else printf("%d\n",dis[e]);
    }
}
