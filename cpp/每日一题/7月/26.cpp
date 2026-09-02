#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e9+7;


void solve()
{
    int n; cin>>n;
    
    if(n>=(1<<20)&&n%(1ll<<20)==0)
    {
        cout<<0<<endl;
        return;
    }

    n%=(1<<20);
    int ans=20;

    for(int i=0;i<=20;i++)
    {
        int t=n+i,cnt=0;
        while(t%2==0)
        {
            t/=2;
            cnt++;
        }
        ans=min({ans,(20-cnt)+i,(1<<20)-n});
    }

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