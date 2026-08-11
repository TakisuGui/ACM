#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=50001;
const int MOD=1e7+7;
const int INF=1e18;

vector<int> sum(4*N);
vector<int> change(4*N);
vector<int> update(4*N);

void up(int i)
{
    sum[i]=sum[i<<1]+sum[i<<1|1];
}

void lazy(int i,int v,int n)
{
    sum[i]=n*v;
    update[i]=true;
    change[i]=v;
}

void down(int i,int ln,int rn)
{
    if(update[i])
    {
        lazy(i<<1,change[i],ln);
        lazy(i<<1|1,change[i],rn);
        update[i]=false;
    }
}

void build(int l,int r,int i)
{
    if(l==r) sum[i]=0;
    else
    {
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
    }
    update[i]=false;
    change[i]=0;
}

void solve()
{
   int n,m; cin>>n>>m;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}