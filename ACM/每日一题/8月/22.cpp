#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e18;
const int MOD=998244353;

void solve()
{
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    bool is_large=false; // 标记 x 的真实数值是否已经 >= 2

    ll x=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]==0) continue;
        else if(a[i]==1) 
        {
            x=(x+1)%MOD;
            if(x >= 2 || is_large) is_large=true;
        }
        else
        {
            if(x==0&&!is_large) 
            {
                x=a[i]%MOD;
                is_large=true;
            }
            else if(!is_large&&x==1)
            {
                x=(1+a[i])%MOD;
                is_large=true;
            }
            else 
            {
                x=(x*(a[i]%MOD))%MOD;
                is_large=true;
            }
        }
    }
    cout<<x%MOD<<endl;
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