#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        char a[50];
        long long x,c=1;
        cin>>x;
        while(x!=0)
        {
            int r=x%2;
            x/=2;
            if(r==0) {
                    a[c++]='0';
            }
            else a[c++]='1';
        }
        a[c]='0';
        int tk=0;
        for(int i=1;i<=c;i++)
        {
            if(a[i]=='1'&&a[i+1]=='0')
            {
                a[i]='0';
                a[i+1]='1';
                for(int j=1;j<i;j++)
                {
                    if(tk)
                    {
                        tk--;
                        a[j]='1';
                    }
                    else a[j]='0';
                }
                break;
            }
            if(a[i]=='1') tk++;
        }
        long long ans=0;
        int j=0;
        for(int i=1;i<=c;i++) {
            int to=a[i]-'0';
                ans+=pow(2,j++)*to;
        }
        printf("Case %d: %d\n",test++,ans);
    }
}
