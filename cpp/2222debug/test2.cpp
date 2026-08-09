#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e7+7;
const int INF=1e18;

vector<int> a(N);
vector<int> add(4*N);
vector<int> max_(4*N);
vector<int> change(4*N);
vector<bool> update(4*N);


void up(int i)
{
    max_[i]=max(max_[i<<1],max_[i<<1|1]);
}

void lazy_add(int i,int v)
{
    add[i]+=v;
    max_[i]+=v;
}

void lazy_update(int i,int v)
{
    max_[i]=v;
    add[i]=0;
    change[i]=v;
    update[i]=true;
}

void down(int i)
{
    if(update[i])
    {
        lazy_update(i<<1,change[i]);
        lazy_update(i<<1|1,change[i]);
        update[i]=false;
    }
    if(add[i])
    {
        lazy_add(i<<1,add[i]);
        lazy_add(i<<1|1,add[i]);
        add[i]=0;
    }
}

void build(int l,int r,int i)
{
    if(l==r) max_[i]=a[l];
    else
    {
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
        up(i);
    }
    add[i]=0;
    update[i]=false;
    change[i]=0;
}

void add_(int jobl,int jobr,int v,int l,int r,int i)
{
    if(jobl<=l&&r<=jobr) lazy_add(i,v);
    else
    {
        int mid=(l+r)>>1;
        down(i);

        if(jobl<=mid) add_(jobl,jobr,v,l,mid,i<<1);
        if(jobr>mid) add_(jobl,jobr,v,mid+1,r,i<<1|1);

        up(i);
    }
}

void update_(int jobl,int jobr,int v,int l,int r,int i)
{
    if(jobl<=l&&r<=jobr) lazy_update(i,v);
    else
    {
        int mid=(l+r)>>1;
        down(i);

        if(jobl<=mid) update_(jobl,jobr,v,l,mid,i<<1);
        if(jobr>mid) update_(jobl,jobr,v,mid+1,r,i<<1|1);

        up(i);
    }
}

int query(int jobl,int jobr,int l,int r,int i)
{
    if(jobl<=l&&r<=jobr) return max_[i];

    int mid=(l+r)>>1;
    down(i);

    int ans=-1e18;
    if(jobl<=mid) ans=max(ans,query(jobl,jobr,l,mid,i<<1));
    if(jobr>mid) ans=max(ans,query(jobl,jobr,mid+1,r,i<<1|1));

    return ans;
}

void solve()
{
    int n,m; cin>>n>>m;

    for(int i=1;i<=n;i++) cin>>a[i];

    build(1,n,1);

    while(m--)
    {
        int op; cin>>op;
        if(op==1)
        {
            int x,y,k; cin>>x>>y>>k;
            add_(x,y,k,1,n,1);
        }
        else if(op==2)
        {
            int l,r,x; cin>>l>>r>>x;
            update_(l,r,x,1,n,1);
        }
        else
        {
            int l,r; cin>>l>>r;
            cout<<query(l,r,1,n,1)<<endl;
        }
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}