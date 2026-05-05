#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) 
    {
        ll n,a,b; cin>>n>>a>>b;
        
        vector<pair<ll,ll>> compare={{28*b,2},{8*a,7},{7*(a+b),8}};
        vector<ll> q(10, 0);
        q[2]=b,q[7]=a,q[8]=a+b;

        sort(compare.begin(),compare.end());

        ll len=compare[2].second;
        ll cost=q[compare[2].second];

        ll group=max(0ll,(n-100)/len);
        ll ans=group*cost;
        n-=(group*len);

        vector<ll> dp(n+1,0);

        for(int i=0;i<=n;i++)
        {
            if(i-2>=0) dp[i]=max(dp[i],dp[i-2]+b);
            if(i-7>=0) dp[i]=max(dp[i],dp[i-7]+a);
            if(i-8>=0) dp[i]=max(dp[i],dp[i-8]+a+b);          
        }

        ans+=dp[n];

        cout<<ans<<endl;
    }
    
    return 0;
}