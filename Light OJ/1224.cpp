#include<bits/stdc++.h>
using namespace std;

int ans=-1;
struct trie{
    trie *path[4];
    int c,sc;
    trie()
    {
        c=0;sc=0;
        for(int i=0;i<4;i++) path[i]=NULL;
    }
};

void ins(string s,trie *root)
{
    trie *node=root;
    for(int i=0;s[i];i++)
    {
        int to;
        if(s[i]=='A') to=0;
        else if(s[i]=='C') to=1;
        else if(s[i]=='G') to=2;
        else if(s[i]=='T') to=3;
        if(node->path[to]==NULL)
        {
            node->path[to]=new trie();
        }
        node->path[to]->sc=node->sc+1;
        node=node->path[to];
        node->c++;
    }
    return;
}
void cnt(trie *root)
{
    if(root==NULL) return;
    for(int i=0;i<4;i++) cnt(root->path[i]);
    ans=max(ans,root->c*root->sc);
}
void dlt(trie *root)
{
    if(root==NULL) return;
    for(int i=0;i<4;i++) {
            if(root->path[i]!=NULL) dlt(root->path[i]);
    }
    delete(root);
    return;
}

int main()
{
    int test;
    cin>>test;
    for(int t=1;t<=test;t++)
    {
        ans=-1;
        int n;
        cin>>n;
        trie *root=new trie();
        while(n--)
        {
            string s;
            cin>>s;
            ins(s,root);
        }
        cnt(root);
        printf("Case %d: %d\n",t,ans);
        dlt(root);
    }
    return 0;
}
