#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6;

ll ans=0;

void solve()
{
    int n; cin>>n;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int a; cin>>a;
        mp[a]++;
    }


    for(int i=1;i<=N;i++)
    {
        ll cur=0;
        for(int j=i;j<=N;j+=i)
        {
            cur+=mp[j]*j;
        }

        ans=max(ans,cur*i);
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