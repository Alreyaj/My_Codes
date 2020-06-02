#include<bits/stdc++.h>
#define PI acos(-1)
using namespace std;

int main()
{
    int t,j=1;
    cin>>t;
    while(t--)
    {
        int n;
        double R;
        cin>>R>>n;
        double r=(sin(PI/n)*R)/(1+sin(PI/n));
        printf("Case %d: %0.10lf\n",j,r);
        j++;
    }

}
