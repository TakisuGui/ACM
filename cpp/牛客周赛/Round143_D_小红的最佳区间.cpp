#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll

void solve()
{
    int n,k; cin>>n>>k;
    
    vector<pair<long long, int>> events;
    for(int i=0; i<n;i++)
    {
        int l,r; cin>>l>>r;
        events.push_back({l-k,-1}); //-1 代表左端点排在,前面优先处理
        events.push_back({r,1});
    }

    sort(events.begin(),events.end());

    int ans=0;
    int cur=0;
    
    for(auto &v : events)
    {
        if(v.second==-1) cur++;
        else
        {
            ans=max(cur,ans);
            cur--;
        }
    }
    ans=max(cur,ans);
    
    cout<<ans<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}