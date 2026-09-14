#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=998244353;

void solve()
{
    int n; cin>>n;
    unordered_map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        mp[x]++;
    }

    if(mp[1]>=mp[0]) cout<<"Bessie"<<endl;
    else cout<<"Elsie"<<endl;
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