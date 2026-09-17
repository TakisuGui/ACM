#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=1e5+10;

ll a[N];
ll b[N];
ll sum_a,sum_b;

void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) {cin>>a[i]; sum_a+=a[i];}
    for(int i=1;i<=n;i++) {cin>>b[i]; sum_b+=b[i];}

    if(sum_a!=sum_b)
    {
        cout<<"-1"<<endl;
        return;
    }

    ll ans=0;
    for(int i=1;i<=n;i++) ans+=max((ll)0,a[i]-b[i]);

    cout<<abs(ans)<<endl;
}

int main()
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