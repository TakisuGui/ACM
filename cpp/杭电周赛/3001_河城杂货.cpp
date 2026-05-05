#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll INF=2e18;

void solve()
{
    ll n,m; cin>>n>>m;
    vector<ll> a(n+1),b(n+2);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n+1;i++) cin>>b[i];

    sort(a.begin()+1,a.end());
    sort(b.begin()+1,b.end());

    vector<ll> pre(n+1,0),suf(n+2,0);
    pre[0]=0;
    for(int j=1;j<=n;j++)
    {
        ll res=a[j]*b[j];
        if (pre[j-1]>=m||res>=m) pre[j]=INF;
        else pre[j]=min(INF,pre[j-1]+res);
    }
    for(int j=n;j>=1;j--)
    {
        ll res=a[j]*b[j+1];
        if (suf[j+1]>=m||res>=m) suf[j]=INF;
        else suf[j]=min(INF,suf[j+1]+res);
    }

    ll min_v=2e18;
    for(int k=1;k<=n+1;k++)
    {
        ll cur=pre[k-1]+suf[k];
        if(cur>=m)
        {
            cout<<"0"<<endl;
            return;
        }

        ll need=m-cur;
        ll value=(need+b[k]-1)/b[k];
        min_v=min(min_v,value);
    }
        cout<<min_v<<"\n";
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}