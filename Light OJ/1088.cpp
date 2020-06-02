#include<bits/stdc++.h>
using namespace std;
const int N=100009;

int a[N];

int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        for(int i=0; i<n; i++) cin>>a[i];
        printf("Case %d:\n",test++);
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            cout<<upper_bound(a+l,a+n,r)-lower_bound(a,a+n,l)<<endl;
        }
    }
}
