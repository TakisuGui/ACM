#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10+10;

ll subp(vector<ll> &a,ll k)
{
    ll n=a.size();
    ll r1=0,r2=0,res=0;
    for(ll l=0;l+1<n;l++)
    {
        r1=max(r1,l+1),r2=max(r2,l+1);
        while(r1<n&&a[r1]-a[l]< k){r1++;}
        while(r2<n&&a[r2]-a[l]<=k){r2++;}
        res+=(r2-r1);
    }
    return res;
}

void solve()
{
    int h,w,k; cin>>h>>w>>k;
    vector<vector<ll>> a(h+1,vector<ll>(w+1,0));
    for(ll i=1;i<=h;i++)
    {
        string s; cin>>s;
        for(ll j=1;j<=w;j++) if(s[j-1]=='1'){a[i][j]=1;}
    }

    for(ll i=1;i<=h;i++)
        for(ll j=1;j<=w;j++)
            a[i][j]+=a[i-1][j];

    int ans=0;
    for(int u=1;u<=h;u++)
    {
        for(int d=u;d<=h;d++)
        {
            vector<ll> b(w+1,0);
            for(ll j=1;j<=w;j++) b[j]=b[j-1]+(a[d][j]-a[u-1][j]);
            ans+=subp(b,k);
        }
    }
        cout<<ans<<endl;
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