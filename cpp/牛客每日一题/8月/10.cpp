#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=3e5+10;
const int MOD=1e7+7;

vector<int> a(N);
vector<int> dp_r(N,1e18);
vector<int> dp_l(N,1e18);


void solve()
{
    int n; cin>>n;
    dp_l[0]=0,dp_r[n+1]=0;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        dp_r[i]=min(dp_r[i-1],a[i]*(n-i+1));
    }
    for(int i=n;i>=1;i--)
    {
        dp_l[i]=min(dp_l[i+1],i*a[i]);
    }
    
    int ans=1e18;
    set<int> q;
    int l=1;
    for(int i=1;i<=n;i++)
    {
        while(q.count(a[i]))
        {
            q.erase(a[l]);
            l++;
        }
        q.insert(a[i]);
        ans=min(ans,dp_l[l-1]+dp_r[i+1]);
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