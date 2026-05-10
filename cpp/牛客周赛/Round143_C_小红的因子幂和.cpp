#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;
const int MOD=1e9+7;

ll ans=0;
vector<pair<ll, int>> factor_list;

ll qpow(ll a,ll b)
{
    a%=MOD;
    int ans=1;
    while(b>0)
    {
        if(b&1) ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }

    return ans;
}

void get_(ll n,map<ll,int>& factors)
{
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            factors[i]++;
            n/=i;
        }
    }
    if (n>1) factors[n]++;
}

void dfs(int index,ll current_d)
{
    if(index==factor_list.size()) 
    {
        ans=(ans+qpow(current_d,current_d))%MOD;
        return;
    }

    ll p=factor_list[index].first;
    int cnt=factor_list[index].second;

    ll j=1;
    for(int i=0;i<=cnt;i++)
    {
        dfs(index+1,current_d*j);
        if(i<cnt) j*=p;
    }

}

void solve()
{
    int x,y; cin>>x>>y;
    map<int,int> factors;
    get_(x,factors);
    get_(y,factors);

    for(auto [p,cnt]: factors) factor_list.push_back({p,cnt});

    dfs(0,1);
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