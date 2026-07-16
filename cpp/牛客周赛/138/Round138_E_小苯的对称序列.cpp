#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll INF = 2e18;

void solve()
{
    int n; cin>>n;
    ll dp=0;
    ll m[2]={-INF,-INF};

    for(int i=1;i<=n;i++)
    {
        ll a; cin>>a;
        int p=abs(a)%2;

        ll ndp=dp;
        if(m[p]!=INF) ndp=max(ndp,a+m[p]);
        m[p]=max(m[p],dp+a);
        dp=ndp;
    }
    cout<<dp<<endl;
}



int main()
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