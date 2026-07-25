#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e3+10;

string s;
vector<vector<int>> dp(N+2,vector<int>(N+2,-1));

int f(int l,int r)
{
    if(l==r) return 1;
    if(l==r-1)
    {
        if((s[l]=='('&&s[r]==')')||(s[l]=='['&&s[r]==']')) return 0;
    }

    if(dp[l][r]!=-1) return dp[l][r];

    int p1=1e9;
    if((s[l]=='('&&s[r]==')')||(s[l]=='['&&s[r]==']')) p1=f(l+1,r-1);
    int p2=1e9;
    for(int k=l;k<r;k++) p2=min(p2,f(l,k)+f(k+1,r));

    int ans=min(p1,p2);
    dp[l][r]=ans;
    return ans;
}


void solve()
{
    cin>>s;
    cout<<f(0,s.size()-1)<<endl;;
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