#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int MOD=998244353;
const int N=3e5+10;

ll qpow(ll a,ll b)
{
    a%=MOD;
    int ans=1;
    while(b>0)
    {
        if(b&1)ans=ans*a%MOD;;
        a=a*a%MOD;
        b>>=1;
    }

    return ans;
}

ll rev(ll n) {return qpow(n,MOD-2);}

void solve()
{
    int n; cin>>n;
    vector<int> a(n),b(n);
    ll total=0;
    for(int i=0;i<n;i++) cin>>a[i],total+=a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    int re_total=rev(total);
    int re_2=rev(2);
    long long total_contribution=0;
    int b_sum=0;

    for(int i=0;i<n;i++)
    {
        int cura=a[i]%MOD;
        int curb=b[i]%MOD;
        int cur_b_sum=b_sum%MOD;

        int win_low=(cura*cur_b_sum)%MOD;
        int win_equal=(cura*curb)%MOD*re_2%MOD;

        total_contribution=(total_contribution+win_equal+win_low)%MOD;

        b_sum+=b[i];
    }

    ll ans=(total_contribution*re_total)%MOD;
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