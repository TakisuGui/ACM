#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e6+10;
const int MOD=1e7+7;
const int INF=1e18;

vector<int> a(N);
vector<int> add(4*N);
vector<int> max_(4*N);
vector<int> min_(N<<2);
int n;

void up1(int i)
{
    max_[i]=max(max_[i<<1],max_[i<<1|1]);
}

void lazy_add1(int i,int v)
{
    add[i]+=v;
    max_[i]+=v;
}

void down1(int i)
{
    if(add[i])
    {
        lazy_add1(i<<1,add[i]);
        lazy_add1(i<<1|1,add[i]);
        add[i]=0;
    }
}

void build1(int l,int r,int i)
{
    if(l==r) max_[i]=a[l];
    else
    {
        int mid=(l+r)>>1;
        build1(l,mid,i<<1);
        build1(mid+1,r,i<<1|1);
        up1(i);
    }
    add[i]=0;
}

void add_(int jobl,int jobr,int v,int l,int r,int i)
{
    if(jobl<=l&&r<=jobr) lazy_add1(i,v);
    else
    {
        int mid=(l+r)>>1;
        down1(i);

        if(jobl<=mid) add_(jobl,jobr,v,l,mid,i<<1);
        if(jobr>mid) add_(jobl,jobr,v,mid+1,r,i<<1|1);

        up1(i);
    }
}


int query(int jobl,int jobr,int l,int r,int i)
{
    if(jobl<=l&&r<=jobr) return max_[i];

    int mid=(l+r)>>1;
    down1(i);

    int ans=-1e18;
    if(jobl<=mid) ans=max(ans,query(jobl,jobr,l,mid,i<<1));
    if(jobr>mid) ans=max(ans,query(jobl,jobr,mid+1,r,i<<1|1));

    return ans;
}


void up2(int i)
{
    min_[i]=min(min_[i<<1],min_[i<<1|1]);
}

void build2(int l,int r,int i)
{
    if(l==r) min_[i]=min(query(1,l,1,n,1),query(l,n,1,n,1));
    else
    {
        int mid=(l+r)>>1;
        build1(l,mid,i<<1);
        build1(mid+1,r,i<<1|1);
        up2(i);
    }
}





void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++) cin>>a[i];

    build1(1,n,1);

    int m; cin>>m;
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