#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"


void solve()
{
    int n,k; cin>>n>>k;
    vector<int> a(n+1);
    int sum=0;
    for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];

    int len=n-k;
    ll cur_sum=0;
    for(int i=0;i<len;i++) cur_sum+=a[i];

    ll max_sum=cur_sum;
    for(int i=len;i<n;i++)
    {
        cur_sum=cur_sum-a[i-len]+a[i];
        max_sum=max(max_sum,cur_sum);
    }

    cout<<max_sum<<endl;
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