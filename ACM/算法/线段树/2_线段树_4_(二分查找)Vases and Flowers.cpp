#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=50001;
const int MOD=1e7+7;
const int INF=1e18;

int n,m;
vector<int> sum(4*N);
vector<int> change(4*N);
vector<bool> update(4*N);

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
    sum[i]=0;
}

void update_(int jobl,int jobr,int v,int l,int r,int i)
{
    if(jobl<=l&&r<=jobr) lazy(i,v,r-l+1);
    else
    {
        int mid=(l+r)>>1;
        down(i,mid-l+1,r-mid);

        if(jobl<=mid) update_(jobl,jobr,v,l,mid,i<<1);
        if(jobr>mid) update_(jobl,jobr,v,mid+1,r,i<<1|1);

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

int find_zero(int i,int k)
{
    int l=i,r=n,ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(mid-i+1-query(i,mid,1,n,1)>=k)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}

int clear_(int l,int r)
{
    l++; r++;
    int ans=query(l,r,1,n,1);
    update_(l,r,0,1,n,1);
    return ans;
}

pair<int,int> insert_(int from,int flowers)
{
    from++;
    int start,end;
    int zero=n-from+1-query(from,n,1,n,1);

    if(zero==0)
    {
        start=0;
        end=0;
    }
    else
    {
        start=find_zero(from,1);
        end=find_zero(from,min(flowers,zero));
        update_(from,end,1,1,n,1);
    }

    start--; end--;
    return {start,end};
}


void solve()
{
    cin>>n>>m;
    build(1,n,1);
    
    while(m--)
    {
        int op; cin>>op;
        if(op==1)
        {
            int a,f; cin>>a>>f;
            auto v=insert_(a,f);

            if(v.first==-1) cout<<"Can not put any one."<<endl;
            else cout<<v.first<<" "<<v.second<<endl;
        }
        else
        {
            int a,b; cin>>a>>b;
            cout<<clear_(a,b)<<endl;
        }
    }
    cout<<endl;
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