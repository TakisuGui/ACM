#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e7+7;


void solve()
{
    int n; cin>>n;
    string s; cin>>s;

    int ans=1;
    for(int i=1;i<n;i++) if(s[i]!=s[i-1]) ans++;

    int dex=0;
    for(int i=1;i<n-1;i++)
    {
        if(s[i-1]!=s[i]&&s[i]!=s[i+1])
        {
            if(s[i-1]!=s[i+1]) dex=max(dex,1ll);
            else dex=max(dex,2ll);
        }
    }
    cout<<ans-dex<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}