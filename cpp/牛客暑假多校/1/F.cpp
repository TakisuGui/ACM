#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll


void solve()
{
    int n,k,x; cin>>n>>k>>x;
    vector<int> a(n+1);
    for(int i=0;i<n;i++)  cin>>a[i];

    int c=(x-a[k]%n+n)%n;
    for(int i=0;i<n;i++) a[i]=(a[i]+c)%n;

    for(int i=0;i<n;i++) cout<<a[i]<<(i!=n-1 ? " " : "");
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