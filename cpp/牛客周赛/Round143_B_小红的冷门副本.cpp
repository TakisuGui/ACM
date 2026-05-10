#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;



void solve()
{
    int n,m,x; cin>>n>>m>>x;
    unordered_map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        int p; cin>>p;
        mp[p]++;
    }

    int ans=0;
    for(auto v:mp) if(v.second<=x) ans++;

    int zero_count=m-mp.size();
    ans+=zero_count;
    
    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}