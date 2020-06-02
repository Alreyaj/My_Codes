///----------------------///
///---Code Written by----///
///-----Al-Shahreyaj-----///
///----------------------///
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ll long long
#define endl "\n"
#define vin vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define pb push_back
#define pq priority_queue
#define all(x) x.begin(),x.end()
#define mod 1000000007
#define cone __builtin_popcount
#define conel __builtin_popcountll
typedef vector<vector<ll> > matrixl;
typedef vector<vector<int> > matrix;
#define N 100009
int Int()
{
    int x;
    scanf("%d", &x);
    return x;
}
 
///Policy Based Set
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    pbds_set;
 
int a[N];
 
int main()
{
    int t = Int(), test = 1;
    while(t--)
    {
        pbds_set st;
        int n = Int();
        for(int i = 1; i <= n; i++) a[i] = Int();
        for(int i = 1; i <= n; i++) st.insert(i);
        for(int i = n; i > 0; i--)
        {
            int id = i - a[i];
            if(i == 1)
            {
                printf("Case %d: %d\n", test++, *st.find_by_order(id - 1));
            }
            st.erase(st.find_by_order(id- 1));
        }
    }
 
    return 0;
}