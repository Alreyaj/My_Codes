#include<bits/stdc++.h>
using namespace std;
#define N 100009
#define ff first
#define ss second
#define all(x) x.begin(), x.end()


int a[N], cn[N];
pair<int, int>pr[N];

struct node{
	int val;
	node *left, *right;
	node(int a = 0, node *b = NULL, node *c = NULL)
	{
		val = a;
		left = b;
		right = c;
	}
};

node *version[N];

void build(node *n, int b, int e)
{
    if(b == e) return;
    n->left = new node();
    n->right = new node();
    int m = (b + e) >> 1;
    build(n->left, b, m);
    build(n->right, m + 1, e);
}

void upd(node *pr, node *n, int b, int e, int pos, int v)
{
    if(b == e)
	{
		n->val = pr->val + v;
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

int qry(node *n, int b, int e, int i, int j)
{
    if(i > e || j < b) return 0;
    if(i <= b && j >= e) return n->val;
    int m = (b + e) >> 1;
    return qry(n->left, b, m, i, j) + qry(n->right, m + 1, e, i, j);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        pr[i] = {a[i], i};
    }
    sort(pr + 1, pr + 1 + n);
    int j = 1;
    cn[j] = pr[1].ff;
    a[pr[1].ss] = j;
    for(int i = 2; i <= n; i++)
    {
        if(pr[i].ff == pr[i - 1].ff)
        {
            a[pr[i].ss] = j;
        }
        else
        {
            j++;
            cn[j] = pr[i].ff;
            a[pr[i].ss] = j;
        }
    }
    version[0] = new node();
    build(version[0], 1, n);
    for(int i = 1; i <= n ; i++)
	{
        version[i] = new node();
        upd(version[i - 1], version[i], 1, n, a[i], 1);
	}
    //for(int i = 1; i <= n; i++) cout << a[i] << " ";
    int x, y, val;
    while(m--)
    {
        scanf("%d %d %d", &x, &y, &val);
        //cout << qry(version[val], 1, n, x, y) << endl;
        int lf = 1, rt = n;
        while(lf <= rt)
		{
            int md = (lf + rt) >> 1;
            int fs = qry(version[y], 1, n, 1, md - 1);
            int cr1 = qry(version[y], 1, n, 1, md);
            int fs2 = qry(version[x - 1], 1, n, 1, md - 1);
            int cr2 = qry(version[x - 1], 1, n, 1, md);
            cr1 = (cr1 - fs) - (cr2 - fs2);
            int co = fs - fs2;
            //cout << md << " " << co << endl;
            if(cr1 > 0 && co == val - 1)
			{
                printf("%d\n", cn[md]);
                break;
			}
			if(co >= val) rt = md - 1;
			else lf = md + 1;
		}
        //cout << chk(1, 1, n, x, y, val) << endl;
        //cout << qry(1, 1, n, x, y, val) << endl;
    }
}

