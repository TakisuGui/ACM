#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e7+7;
const int INF=1e18;

int n,m;
vector<int> a(N);
vector<int> sum(4*N);
vector<int> max_(4*N);

void up(int i)
{
    sum[i]=sum[i<<1]+sum[i<<1|1];
    max_[i]=max(max_[i<<1],max_[i<<1|1]);
}

void build(int l,int r,int i)
{
    if(l==r) sum[i]=a[l],max_[i]=a[l];
    else
    {
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
        up(i);
    }
}

void mod(int jobl,int jobr,int v,int l,int r,int i)
{
    if(v>max_[i]) return;

    if(l==r)
    {
        sum[i]%=v;
        max_[i]%=v;
    }
    else
    {
        int mid=(l+r)>>1;
        if(jobl<=mid) mod(jobl,jobr,v,l,mid,i<<1);
        if (jobr>mid) mod(jobl,jobr,v,mid+1,r,i<<1|1);

        up(i);
    }
}

void update(int jobi,int v,int l,int r,int i)
{
    if(l==r) sum[i]=max_[i]=v;
    else
    {
        int mid=(l+r)>>1;
        if(jobi<=mid) update(jobi,v,l,mid,i<<1);
        else update(jobi,v,mid+1,r,i<<1|1);

        up(i);
    }
}

int query(int jobl,int jobr,int l,int r,int i)
{
    if(jobl<=l&&r<=jobr) return sum[i];

    int mid=(l+r)>>1;
    int ans=0;

    if(jobl<=mid) ans+=query(jobl,jobr,l,mid,i<<1);
    if(jobr>mid) ans+=query(jobl,jobr,mid+1,r,i<<1|1);
    return ans;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,n,1);

    while(m--)
    {
        int op; cin>>op;
        if(op==1)
        {
            int l,r; cin>>l>>r;
            cout<<query(l,r,1,n,1)<<endl;
        }
        else if(op==2)
        {
            int l,r,x; cin>>l>>r>>x;
            mod(l,r,x,1,n,1);
        }
        else
        {
            int k,x; cin>>k>>x;
            update(k,x,1,n,1);
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
