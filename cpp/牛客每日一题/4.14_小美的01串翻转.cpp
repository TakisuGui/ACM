#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int dp[2010][2];

void solve()
{
    string text; cin>>text;
    ll ans=0;

    for(int j=0;j<text.size();j++)
    {
        ll sum=0;
        dp[j][0]=0; dp[j][1]=1;
        for(int i=j+1;i<text.size();i++)
        {
            if(text[i]==text[i-1])
            {
                dp[i][0]=dp[i-1][1];
                dp[i][1]=dp[i-1][0]+1;
            }
            else
            {
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1]+1;
            }
            sum+=min(dp[i][0],dp[i][1]);
        }
        ans+=sum;
    }

    cout<<ans<<endl;
}

int main()
{
    solve();

    return 0;
}