#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n,k; cin>>n>>k;
    
    vector<pair<int,int>> st;

    for(int i=0;i<n;i++)
    {
        int x; cin>>x;

        if(st.empty()||st.back().first!=x)
        {
            st.push_back({x,1});
        }
        else st.back().second++;

        if(st.back().second==k) st.pop_back();
    }
    
    ll ans=0;
    for(auto [ch,cnt]: st) ans+=cnt;
    cout<<ans<<endl;

    for(auto [ch,cnt]: st)
    {
        for(int i=1;i<=cnt;i++) cout<<ch<<" ";
    }

    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}