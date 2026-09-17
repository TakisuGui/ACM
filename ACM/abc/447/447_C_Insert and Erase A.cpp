#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s,t;

int main()
{
    cin>>s>>t;
    int i=0,j=0;
    ll ans=0;
    string s_tem,t_tem;

    for(char c:s) if(c!='A') s_tem+=c;
    for(char c:t) if(c!='A') t_tem+=c;
    if(s_tem!=t_tem)
    {
        cout<<"-1"<<endl;
        return 0;
    }

    while(i<s.size()&&j<t.size())
    {
        if(s[i]==t[j])
        {
            i++; j++;
            continue;
        }

        else if(s[i]!=t[j]&&t[j]=='A')//插入A
        {
            ans++;
            j++;
        }
        else if(s[i]!=t[j]&&s[i]=='A')//删除A
        {
            ans++;
            i++;
        }
        else
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }

    while(j<t.size())
    {
        if(t[j]=='A')
        {
            ans++;
            j++;
        }
        else
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }

    while(i<s.size())
    {
        if(s[i]=='A')
        {
            ans++;
            i++;
        }
        else
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }


    if(i==s.size()&&j==t.size()) cout<<ans<<endl;
    else cout<<"-1"<<endl;

    return 0;
}