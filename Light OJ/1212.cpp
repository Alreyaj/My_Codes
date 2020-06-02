#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    for(int t=1;t<=test;t++)
    {

        int a[100];
        int n,m,l=50,r=49;
        cin>>n>>m;
        printf("Case %d:\n",t);
        while(m--)
        {
            string s;
            cin>>s;
            if(s=="pushLeft")
            {
                int x;
                cin>>x;
                if(r-l<n-1)
                {
                    l--;
                    a[l]=x;
                    cout<<"Pushed in left: "<<x<<endl;
                }
                else cout<<"The queue is full"<<endl;
            }
            else if(s=="pushRight")
                {
                int x;
                cin>>x;
                if(r-l<n-1)
                {
                    r++;
                    a[r]=x;
                    cout<<"Pushed in right: "<<x<<endl;
                }
                else cout<<"The queue is full"<<endl;
            }
            else if(s=="popLeft")
            {
                if(r>=l){
                cout<<"Popped from left: "<<a[l]<<endl;
                l++;
                }
                else cout<<"The queue is empty"<<endl;
            }
            else if(s=="popRight")
            {
                if(r>=l){
                cout<<"Popped from right: "<<a[r]<<endl;
                r--;
                }
                else cout<<"The queue is empty"<<endl;
            }
        }
    }
}
