#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,k; cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
    {
        ll x; cin>>x; x%=k;
        a[i]=x;
    }

    sort(a.begin(),a.end());

    ll ans=a[n-1]-a[0];
    for(int i=0;i<n-1;i++)
    {
        ans=min(ans,a[i]+k-a[(i+1)%n]);
    }

    cout<<ans<<endl;

    return 0;
}