#include<bits/stdc++.h>
using namespace std;

struct lst
{
    int v;
    lst *nxt;
    lst()
    {
        v=0;
        nxt=NULL;
    }
};

void prnt(lst *node)
{
    node=node->nxt;
    while(node->nxt!=NULL)
    {
        cout<<node->v<<" ";
        node=node->nxt;
    }
    cout<<endl;
}

int main()
{
    lst *root=new lst();
    lst *node=new lst();
    root->nxt=node;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        node->v=x;
        lst *nnode=new lst();
        node->nxt=nnode;
        node=nnode;
    }
    prnt(root);

}
