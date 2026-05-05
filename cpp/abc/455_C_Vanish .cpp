#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+10;

ll a[N];

void solve()
{
    int n,k; cin>>n>>k;
    unordered_map<ll,ll> mp;
    ll sum=0;

    for(int i=1;i<=n;i++)
    {
        ll x; cin>>x;
        mp[x]++;
        sum+=x;
    }

    int i=1;

    for(auto&[key,value] : mp)
    {
        a[i++]=1ll*key*value;
    }

    sort(a+1,a+i);

    for(int j=1;j<=k&&j<i;j++)
    {
        sum-=a[i-j];
    }

    cout<<sum<<endl;
}


int main()
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