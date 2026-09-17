#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=3e5+10;
const int MOD=1e7+7;


void solve()
{
    int n; cin>>n;
    vector<string> s(4);

    for(int i=0;i<3;i++) cin>>s[i];

    if(n>8)
    {
        cout<<0<<endl;
        return;
    }

    vector<int> pass(n,0);
    for(int i=0;i<n;i++)
    {
        for(int p=0;p<8;p++)
        {
            bool ok=true;
            for(int r=0;r<3;r++)
            {
                char ch=s[r][i];
                if(ch!='?')
                {
                    int bit=(p>>(2-r))&1;
                    if(ch-'0'!=bit) ok=false;
                }
            }
            if(ok) pass[i]|=(1<<p);
        }
    }

    vector<ll> dp(256,0),ndp(256,0);
    dp[0]=1;

    for(int i=0;i<n;i++)
    {
        int cur=pass[i];
        fill(ndp.begin(),ndp.end(),0);

        for(int mask=0;mask<256;mask++)
        {
            if(!dp[mask]) continue;

            for(int p=0;p<8;p++)
            {
                if((cur>>p)&1)
                {
                    if(!((mask>>p)&1))
                    {
                        ndp[mask|(1<<p)]+=dp[mask];
                    }
                }
            }
        }
        dp.swap(ndp);
    }

    ll ans=0;
    for(int mask=0;mask<256;mask++) ans+=dp[mask];
    cout<<ans<<endl;
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