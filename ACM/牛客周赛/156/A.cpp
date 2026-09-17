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
    string s; cin>>s;
    int ans=-1;
    for(auto& c : s)
    {
        if('0'<=c&&c<='9')
        {
            ans=c-'0';
            break;
        }
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