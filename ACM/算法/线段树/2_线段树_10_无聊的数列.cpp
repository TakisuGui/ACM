#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e7+7;
const int INF=1e18;

vector<int> diff(N);
vector<int> add(4*N);
vector<int> sum(4*N);

void up(int i)
{
    sum[i]=sum[i<<1]+sum[i<<1|1];
}

void lazy_(int i,int v,int n)
{
    add[i]+=v;
    sum[i]+=n*v;
}

void down(int i,int ln,int rn)
{
    if(add[i]!=0)
    {
        lazy_(i<<1,add[i],ln);
        lazy_(i<<1|1,add[i],rn);
        add[i]=0;
    }
}

void build(int l,int r,int i)
{
    if(l==r) sum[i]=diff[l];
    else
    {
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
        up(i);
    }
    add[i]=0;
}

void add_(int jobl,int jobr,int v,int l,int r,int i)
{
    if(jobl<=l&&r<=jobr) lazy_(i,v,r-l+1);
    else
    {
        int mid=(l+r)>>1;
        down(i,mid-l+1,r-mid);

        if(jobl<=mid) add_(jobl,jobr,v,l,mid,i<<1);
        if(jobr>mid) add_(jobl,jobr,v,mid+1,r,i<<1|1);

        up(i);
    }
}

int query(int jobl,int jobr,int l,int r,int i)
{
    if(jobl<=l&&r<=jobr) return sum[i];

    int mid=(l+r)>>1;
    down(i,mid-l+1,r-mid);

    int ans=0;
    if(jobl<=mid) ans+=query(jobl,jobr,l,mid,i<<1);
    if(jobr>mid) ans+=query(jobl,jobr,mid+1,r,i<<1|1);

    return ans;
}

void solve()
{
    int n,m; cin>>n>>m;

    for(int i=1,cur,pre=0;i<=n;i++)
    {
        cin>>cur;
        diff[i]=cur-pre;
        pre=cur;
    }
    build(1,n,1);

    while(m--)
    {
        int op; cin>>op;
        if(op==1)
        {
           int l,r,k,d; cin>>l>>r>>k>>d;
           int e=k+d*(r-l);
           add_(l,l,k,1,n,1);
           if(l+1<=r) add_(l+1,r,d,1,n,1);
           if(r<n) add_(r+1,r+1,-e,1,n,1);
        }
        else
        {
            int p; cin>>p;
            cout<<query(1,p,1,n,1)<<endl;;
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