#include<bits/stdc++.h>
using namespace std;

struct trie{
    trie *path[26];
};

int main()
{
    trie *root=new trie();
    string s,v;
    int k,ans=0;
    cin>>s>>v>>k;
    for(int i=0;s[i];i++)
    {
        trie *node=root;
        int c=0;
        for(int j=i;s[j];j++)
        {
            if(v[s[j]-'a']=='0') c++;
            if(c>k) break;
            int to=s[j]-'a';
            if(node->path[to]==NULL)
            {
                ans++;
                node->path[to]=new trie();
            }
            node=node->path[to];
        }
    }
    cout<<ans<<endl;
}
