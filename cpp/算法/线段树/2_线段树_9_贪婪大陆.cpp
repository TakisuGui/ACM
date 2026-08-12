#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e7+7;
const int INF=1e18;

vector<int> start(4*N);
vector<int> end_(4*N);

void up(int i)
{
    start[i]=start[i<<1]+start[i<<1|1];
    end_[i]=end_[i<<1]+end_[i<<1|1];
}


void build(int l,int r,int i)
{
    if(l==r) start[i]=0,end_[i]=0;
    else
    {
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
        up(i);
    }
    start[i]=0,end_[i]=0;
}

void add_(int jobt,int jobi,int l,int r,int i)
{
    if(l==r)
    {
        if(jobt==0) start[i]++;
        else end_[i]++;
    }
    else
    {
        int mid=(l+r)>>1;
        if(jobi<=mid) add_(jobt,jobi,l,mid,i<<1);
        if(jobi>mid) add_(jobt,jobi,mid+1,r,i<<1|1);

        up(i);
    }
}

int query(int jobt,int jobl,int jobr,int l,int r,int i)
{
    if(jobl<=l&&r<=jobr) return jobt==0 ? start[i] : end_[i];

    int mid=(l+r)>>1;
    int ans=0;
    if(jobl<=mid) ans+=query(jobt,jobl,jobr,l,mid,i<<1);
    if(jobr>mid) ans+=query(jobt,jobl,jobr,mid+1,r,i<<1|1);

    return ans;
}

void solve()
{
    int n,m; cin>>n>>m;
    build(1,n,1);

    while(m--)
    {
        int op; cin>>op;
        if(op==1)
        {
            int x,y; cin>>x>>y;
            add_(0,x,1,n,1);
            add_(1,y,1,n,1);
        }
        else
        {
            int x,y; cin>>x>>y;
            int s=query(0,1,y,1,n,1);
            int e= x==1 ? 0 : query(1,1,x-1,1,n,1);

            cout<<s-e<<endl;
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