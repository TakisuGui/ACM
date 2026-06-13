#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e3+10;

void solve()
{
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    unordered_map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        mp[x]++;
    }

    int ans=0;
    for(auto [key,cnt] : mp)
    {
        if(cnt==1)
        {
            cout<<-1<<endl;
            return;
        }
        ans+=(cnt+1)/2;
    }

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