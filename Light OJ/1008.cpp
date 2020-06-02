#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,j=1;
    cin>>t;
    while(t--)
    {
        long long x;
        cin>>x;
        int c,r;
        int l=sqrt(x);
        if(l!=sqrt(x)) l++;
        c=1;
        r=l;
        long long n=l*l;
        int d=n-x;
        if(d<l)
        {
            c+=d;
        }
        else
        {
            c+=l-1;
            r-=d-(l-1);
        }
        if(l%2!=0)
            cout<<"Case "<<j<<": "<<c<<" "<<r<<endl;
        else cout<<"Case "<<j<<": "<<r<<" "<<c<<endl;
        /*for(int i=1; i<l; i++)
        {
            if(n==x)
            {
                if(l%2!=0)
                    cout<<"Case "<<j<<": "<<c<<" "<<r<<endl;
                else cout<<"Case "<<j<<": "<<r<<" "<<c<<endl;
                break;
            }
            c++;
            n--;
        }
        if(n!=x)
        {
            for(int i=1; i<l; i++)
            {
                if(n==x)
                {
                    if(l%2!=0)
                        cout<<"Case "<<j<<": "<<c<<" "<<r<<endl;
                    else cout<<"Case "<<j<<": "<<r<<" "<<c<<endl;
                    break;
                }
                r--;
                n--;
            }
        }*/

        j++;
    }
    return 0;
}
