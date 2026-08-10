#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=3e5+10;
const int MOD=1e7+7;


void solve()
{
    int n; cin>>n;
    string s; cin>>s;
    int ans=0;
    for(char c='a';c<='z';c+=1)
    {
        string t;
        for(auto&  cur : s)
        {
            if(cur!=c) t+=cur;
        }

        if(t!=s&&t==string(t.rbegin(),t.rend())) ans++;
    }
    cout<<ans<<endl;
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