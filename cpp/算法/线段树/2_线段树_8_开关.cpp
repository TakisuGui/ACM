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

vector<int> sum(N<<2);
vector<bool> reverse_(N<<2);

void up(int i)
{
    sum[i]=sum[i<<1]+sum[i<<1|1];
}

void lazy(int i,int n)
{
    sum[i]=n-sum[i];
    reverse_[i]=!reverse_[i];
}

void down(int i,int ln,int rn)
{
    if(reverse_[i])
    {
        lazy(i<<1,ln);
        lazy(i<<1|1,rn);
        reverse_[i]=!reverse_[i];
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
        up(i);
    }
    sum[i]=0;
    reverse_[i]=false;
}

void to_reverse(int jobl,int jobr,int l,int r,int i)
{
    if(jobl<=l&&r<=jobr) lazy(i,r-l+1);
    else
    {
        int mid=(l+r)>>1;
        down(i,mid-l+1,r-mid);

        if(jobl<=mid) to_reverse(jobl,jobr,l,mid,i<<1);
        if(jobr>mid) to_reverse(jobl,jobr,mid+1,r,i<<1|1);
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
    cin>>n>>m;
    build(1,n,1);


    while(m--)
    {
        int c,a,b; cin>>c>>a>>b;
        if(c==0) to_reverse(a,b,1,n,1);
        else cout<<query(a,b,1,n,1)<<endl;
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