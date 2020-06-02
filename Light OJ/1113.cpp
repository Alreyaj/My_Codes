#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        stack<string> s,sx;
        cout<<"Case "<<k<<":"<<endl;
        s.push("http://www.lightoj.com/");
        while(1)
        {
            bool b=false;
            string s1,s2;
            cin>>s1;
            if(s1=="VISIT")
            {
                cin>>s2;
                if(s.empty()) s.push("http://www.lightoj.com/");
                s.push(s2);
                cout<<s.top()<<endl;
                if(!sx.empty())
                {
                    while(!sx.empty()) sx.pop();
                }
            }
            else if(s1=="BACK")
            {
                //s.pop();
                if(!s.empty())
                {
                    string ss=s.top();
                    sx.push(ss);
                    s.pop();
                    if(!s.empty())
                    {
                        cout<<s.top()<<endl;
                    }
                    else cout<<"Ignored"<<endl;
                }
                else cout<<"Ignored"<<endl;
            }
            else if(s1=="FORWARD")
            {
                if(!sx.empty())
                {
                    if(s.empty())
                    {
                        string ss=sx.top();
                        s.push(ss);
                        sx.pop();
                    }
                    if(!sx.empty())
                    {
                        string ss=sx.top();
                        s.push(ss);
                        sx.pop();
                        cout<<s.top()<<endl;
                    }
                    else cout<<"Ignored"<<endl;
                }
                else cout<<"Ignored"<<endl;
            }
            else break;
        }
    }
    return 0;
}
