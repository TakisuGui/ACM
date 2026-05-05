#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;

int dp1[N];
int dp2[N];
int ans=-1e9;

void slove()
{
    int x; cin>>x;
    int a[x+1]; ans=-1e9;
    for(int i=1;i<=x;i++) cin>>a[i];

    for(int i=0;i<=x+5;i++) dp1[i]=dp2[i]=-1e9;

    int cur=-1e9;
    for(int i=1;i<=x;i++)
    {
        cur=max(cur+a[i],a[i]);
        dp1[i]=max(dp1[i-1],cur);

    }
    cur=-1e9;
    for(int i=x;i>=1;i--)
    {
        cur=max(cur+a[i],a[i]);
        dp2[i]=max(dp2[i+1],cur);
    }

    for(int i=3;i<=x-2;i++) ans=max(ans,dp1[i-2]+a[i]+dp2[i+2]);

    cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
        slove();
    }

    return 0;
}