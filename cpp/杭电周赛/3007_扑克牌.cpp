#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;

void solve()
{
    int n,m,k; cin>>n>>m>>k;
    vector<ll> a(2*n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }

    vector<ll> pre(2*n+1,0);
    for(int i=1;i<=2*n;i++)
    {
        if(i<=m) pre[i]=a[i];
        else pre[i]=a[i]+pre[i-m];
    }

    ll max_sum=-2e18;

    for(int i=1;i<=n;i++)
    {
        int first=i+k-1;
        int count=(n-k)/m+1;
        int last=first+(count-1)*m;

        ll current_sum=pre[last]-(first>m ? pre[first-m]:0);
        max_sum=max(max_sum,current_sum);
    }

    cout<<max_sum<<endl;
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