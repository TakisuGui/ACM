#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e6+10;
const int MOD=998244353;


void solve()
{
    int n; cin>>n;
    vector<int> a(n+1);
    map<ll,vector<ll>> groups;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        groups[x-i].push_back(x);
    }

    int ans=0;
    for(auto& [t,vec] : groups)
    {
        vector<int> cur=vec;
        sort(cur.rbegin(),cur.rend());
        
        for(int i=0;i+1<cur.size();i+=2)
        {
            if(cur[i]+cur[i+1]>0) ans+=cur[i]+cur[i+1];
            else break;
        }
    }
    cout<<ans<<endl;
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