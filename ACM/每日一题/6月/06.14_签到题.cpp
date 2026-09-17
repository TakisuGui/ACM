#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e3+10;

void solve()
{
    int n,m; cin>>n>>m;
    map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        mp[x]++;
    }

    vector<pair<int, int>> vec(mp.begin(), mp.end());
    int s=vec.size();
    vector<int> last(s+1,0);
    for(int i=s-1;i>=0;i--) last[i]=last[i+1]+vec[i].second;
    
    int ans=0;
    for(int i=0;i<s;i++)
    {
        if(last[i]>=m)
        {
            ans=max(ans,vec[i].second);
        }
        else break;
    }

    cout<<min(m,ans)<<endl;
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