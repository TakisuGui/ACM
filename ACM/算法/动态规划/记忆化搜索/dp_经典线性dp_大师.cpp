#include<bits/stdc++.h>
using namespace std;

const int N=1e4+10;
typedef long long ll;
const int MOD = 998244353;
int n;

int main()
{
    cin>>n;
    int a[n+4];
    for(int i=1;i<=n;i++) cin>>a[i];

    vector< unordered_map<int,int> >dp(n+4);

    ll ans=n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            int d=a[i]-a[j];
            int ways=(dp[j][d]+1)%MOD;
            dp[i][d]=(dp[i][d]+ways)%MOD;
            ans=(ans+ways)%MOD;
        }
    }

    cout<<ans%MOD<<endl;

    return 0;
}