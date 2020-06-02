#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        bool b[m+10][n+10];
        int c=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                {
                    if(!b[i][j])
                    {
                        b[i][j]=true;
                        b[i+2][j+1]=true;
                        b[i+2][j-1]=true;
                        b[i-2][j+1]=true;
                        b[i-2][j-1]=true;
                        b[i+1][j+2]=true;
                        b[i+1][j-2]=true;
                        b[i-1][j+2]=true;
                        b[i-1][j-2]=true;
                        c++;
                    }
                }
        }
        cout<<c<<endl;
    }
}
