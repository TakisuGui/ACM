#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=2e3+10;
const int MOD=1e7+7;

vector<int> a(N);
vector<int> dp(N,-1);

void solve()
{
    int n; cin>>n;
    vector<int> l(n+1,0);
    vector<int> r(n+1,n+1); 
    dp[0]=0;

    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=2;i<=n;i++)
    {
        for(int j=i-1;j>=1;j--) 
        if(__gcd(a[i],a[j])>1) {l[i]=j; break;}
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++) 
        if(__gcd(a[i],a[j])>1) {r[i]=j; break;}
    }

    for(int i=1;i<=n;i++)
    {
        int mini=i;
        for(int j=i;j>=1;j--)
        {
            if(r[j]>i) mini=min(mini,l[j]);

            if(mini>=j&&dp[j-1]!=-1)
            {
                dp[i]=max(dp[i],dp[j-1]+1);
            }
        }
    }
    cout<<dp[n]<<endl;
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