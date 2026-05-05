#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353;

void solve()
{
    int n; string s;
    cin>>n>>s;

    vector<vector<bool>> flag(n+1,vector<bool>(n+1));

    for(int i=0;i<n;i++)
    {
        int l=i,r=i;
        while(l>=0&&r<n&&s[l]==s[r])
        {
            flag[l+1][r+1]=true;
            l--,r++;
        }

        l=i,r=i+1;
        while(l>=0&&r<n&&s[l]==s[r])
        {
            flag[l+1][r+1]=true;
            l--,r++;
        }
    }

    vector<ll> dp1(n+1),dp2(n+1);
    dp1[0]=1,dp2[0]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(flag[j][i])
            {
               int len=i-j+1;
               ll sq=(1ll*len*len)%MOD;

               dp1[i]=(dp1[i]+dp1[j-1])%MOD;

               ll contri=(dp2[j-1]+dp1[j-1]*sq)%MOD;
               dp2[i]=(dp2[i]+contri)%MOD;
            }
        }
    }

    cout<<dp2[n]<<endl;
}

int main()
{
    int t; cin>>t;
        
    while(t--)
    {
        solve();
    }

    return 0;
}