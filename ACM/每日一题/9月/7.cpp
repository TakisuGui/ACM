#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=998244353;


vector<int> get_(int n)
{
    vector<int> ans;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ans.push_back(i);
            if(i*i!=n) ans.push_back(n/i);
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

void solve()
{
    int w,h,d; cin>>w>>h>>d;
    int n; cin>>n;

    vector<ll> divs=get_(n);

    for(int kw : divs)
    {
        if(w%kw!=0) continue;
        for(int kh : divs)
        {
            if(h%kh!=0) continue;
            if(n%(kh*kw)!=0) continue;

            ll kd=n/(kh*kw);
            if(d%kd!=0) continue;
            cout<<kw-1<<" "<<kh-1<<" "<<kd-1<<endl;
            return;
        }
    }
    
    cout<<-1<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}