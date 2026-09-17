#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e7+7;


void solve()
{
    int n; cin>>n;
    vector<int> a(n);
    int sum=0;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.rbegin(),a.rend());

    int s=a[0]%MOD;
    for(int i=1;i<n;i++)
    {
        if(a[i]+s>=0)
        {
            sum=sum+a[i]+s;
            s=a[i]+s;
        }
        else break;
    }

    cout<<sum%MOD<<endl;
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