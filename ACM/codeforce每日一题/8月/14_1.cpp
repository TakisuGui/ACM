#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e18;
const int MOD=1e7+7;


void solve()
{
    string s; getline(cin,s);

    bool has_q=false;

    string ans; ans+="<";

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='"') 
        {
            if(!has_q) has_q=true;
            else
            {
                cout<<ans<<">"<<endl;
                ans="<";
                has_q=false;
            }
        }
        else if(s[i]==' ')
        {
            if(has_q) ans+=s[i];
            else
            {
                if(ans=="<") continue;
                else
                {
                    cout<<ans<<">"<<endl;
                    ans="<";
                }
            }
        }
        else ans+=s[i];
    }

    if(ans!="<") cout<<ans<<">"<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}