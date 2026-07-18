#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
    int n,m; cin>>n>>m;
    vector<int> a(n+1);
    vector<int> pre(n+1,0);
    int ans=0;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=a[i]+pre[i-1];
    }

    vector<int> b(m);
    for(int i=0;i<m;i++)  cin>>b[i];

    sort(b.rbegin(),b.rend());

    if(!b.empty()&&b[0]<n) ans+=pre[n]-pre[b[0]];

    for(int i=0;i<b.size();i++)
    {
        int l=(i+1<b.size() ? b[i+1] : 0);
        int r=b[i];

        ans+=abs(pre[r]-pre[l]);
    }

    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}