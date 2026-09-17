#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=101;
const int MOD=1e7+7;
const int INF=1e18;

vector<int> a(201);
vector<int> dex2(201);
vector<int> dex5(201);

vector<vector<int>> dp(201,vector<int>(5005,-1)); 

int get_dex(int i,int n)
{
    int ans=0;
    while(n%i==0)
    {
        n=n/i;
        ans++;
    }
    return ans;
}

void solve()
{
    int n,k; cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        dex2[i]=get_dex(2,x);
        dex5[i]=get_dex(5,x);
    }
    
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=k;j>=1;j--)
        {
            for(int t=25*n;t>=dex5[i];t--)
            {
                if(dp[j-1][t-dex5[i]]!=-1)
                dp[j][t]=max(dp[j][t],dp[j-1][t-dex5[i]]+dex2[i]);
            }
        }
    }

    int ans=0;
    for(int i=1;i<=n*25;i++)
    {
        ans=max(ans,min(dp[k][i],i));
    }
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