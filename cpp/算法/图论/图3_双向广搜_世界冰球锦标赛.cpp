#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=40;
const ll M=(1ll<<20)+500;

ll arr[N];
int n;
ll w;

void f(int i,int e,ll s,ll w,vector<ll>& res)
{
    if(s>w) return;

    if(i==e)
    {
        res.push_back(s);
        return;
    }
    else
    {
        f(i+1,e,s,w,res);
        f(i+1,e,s+arr[i],w,res);
    }
    return;
}

void solve()
{
    cin>>n>>w;
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<ll> lsum, rsum;
    f(0,n>>1,0,w,lsum);
    f(n>>1,n,0,w,rsum);

    sort(lsum.begin(), lsum.end());
    sort(rsum.begin(), rsum.end());
    ll ans=0;

    int j=0;
    int rsize=rsum.size();
    for(int i=lsum.size()-1;i>=0;i--)
    {
        while(j<rsize&&lsum[i]+rsum[j]<=w) j++;

        ans+=j;
    }

    cout<<ans<<endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}