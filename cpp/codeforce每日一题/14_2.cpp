#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e18;
const int MOD=1e7+7;


void solve()
{
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    sort(a.begin()+1,a.begin()+1+n);
   
    vector<int> cnt(n+1,0);
    for(int i=1;i<=n;i++) cnt[a[i]]++;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

    for(int i=1;i<=n;i++) 
    {
        if(cnt[i]>0) q.push({cnt[i],i});
    }
    
    int ans=0;
    int lastAlice=-1;
    
    while(!q.empty())
    {
        auto [freq,v]=q.top(); q.pop();

        if(v>lastAlice)
        {
            ans++;
            lastAlice=v;
        }
    }
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