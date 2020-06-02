#include<bits/stdc++.h>
using namespace std;
#define N 1000009

int a[N], id[N];

struct node
{
    int val;
    node *left, *right;
    node(int a = 0, node *b = NULL, node *c = NULL)
    {
        val = a;
        left = b;
        right = c;
    }
};

node *version[N], *version2[N];

void build(node *n, int b, int e)
{
    if(b == e) return;
    int m = (b + e) >> 1;
    n->left = new node();
    n->right = new node();
    build(n->left, b, m);
    build(n->right, m + 1, e);
}

void upd(node *pr, node *n, int b, int e, int pos, int v)
{
    if(b == e)
    {
        n->val = v;
        return;
    }
    int m = (b + e) >> 1;
    if(pos <= m)
    {
        n->left = new node();
        upd(pr->left, n->left, b, m, pos, v);
        n->right = pr->right;
    }
    else
    {
        n->right = new node();
        upd(pr->right, n->right, m + 1, e, pos, v);
        n->left = pr->left;
    }
    n->val = n->left->val + n->right->val;
}

void nupd(node *n, int b, int e, int pos, int v)
{
    if(b == e)
    {
        n->val = v;
        return;
    }
    int m = (b + e) >> 1;
    if(pos <= m)
    {
        n->left = new node();
        nupd(n->left, b, m, pos, v);
    }
    else
    {
        n->right = new node();
        nupd(n->right, m + 1, e, pos, v);
    }
    n->val = n->left->val + n->right->val;
}

int qry(node *n, int b, int e, int pos)
{
    if(pos > e) return 0;
    if(pos <= b) return n->val;
    int m = (b + e) >> 1;
    return qry(n->left, b, m, pos) + qry(n->right, m + 1, e, pos);
}

void dlt(node *n, int b, int e)
{
//    if(b == e)
//    {
//        delete(n);
//        return;
//    }
    int m = (b + e) >> 1;
    if(n->left != NULL) dlt(n->left, b, m);
    if(n->right != NULL) dlt(n->right, m + 1, e);
    delete(n);
}


int main()
{
    int t = 1, test = 1, n, q, x, y;
    //scanf("%d", &t);
    while(t--)
    {
        for(int i = 0; i < N; i++)
        {
            if(version[i] == NULL ) version[i] = new node();
            if(version2[i] == NULL) version2[i] = new node();
        }


        memset(id, 0, sizeof(id));
        scanf("%d ", &n);
        //version[0] = new node();
        build(version[0], 1, n);
        version2[0] = version[0];
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            //version[i] = new node();
            upd(version2[i - 1], version[i], 1, n, i, 1);
            //cout << id[a[i]] << endl;
            if(id[a[i]])
            {
                //version2[i] = new node();
                //cout << id[a[i]] << endl;
                upd(version[i], version2[i], 1, n, id[a[i]], 0);
            }
           	 else version2[i] = version[i];
            //cout << qry(version[i - 1], 1, n, 3) << endl;
            id[a[i]] = i;
        }
        //printf("Case %d:\n", test++);
        //cout << qry(version[4], 1, n, 1) << endl;
        scanf("%d ", &q);
        while(q--)
        {
            scanf("%d %d", &x, &y);
            printf("%d\n", qry(version2[y], 1, n, x));
        }
//        for(int i = 0; i < N; i++)
//        {
//            if(version[i] != NULL) dlt(version[i], 1, n);
//            if(version2[i] != NULL) dlt(version2[i], 1, n);
//            version[i] = NULL;
//            version2[i] = NULL;
//        }
//        cout << version[1]->val << endl;

    }
}
