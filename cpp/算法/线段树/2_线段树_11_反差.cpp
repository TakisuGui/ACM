#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
const int N=1e5+10;
const int MOD=1e7+7;
const int INF=1e18;

vector<double> a(N);
vector<double> add(4*N);
vector<double> sum1(4*N);
vector<double> sum2(4*N);

void up(int i)
{
    sum1[i]=sum1[i<<1]+sum1[i<<1|1];
    sum2[i]=sum2[i<<1]+sum2[i<<1|1];
}

void lazy_(int i,double v,int n)
{
    sum2[i]+=v*v*n+sum1[i]*v*2;
    add[i]+=v;
    sum1[i]+=n*v;
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
    if(l==r) sum1[i]=a[l],sum2[i]=a[l]*a[l];
    else
    {
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
        up(i);
    }
    add[i]=0;
}

void add_(int jobl,int jobr,double v,int l,int r,int i)
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

double query(vector<double>& sum,int jobl,int jobr,int l,int r,int i)
{
    if(jobl<=l&&r<=jobr) return sum[i];

    int mid=(l+r)>>1;
    down(i,mid-l+1,r-mid);

    double ans=0;
    if(jobl<=mid) ans+=query(sum,jobl,jobr,l,mid,i<<1);
    if(jobr>mid) ans+=query(sum,jobl,jobr,mid+1,r,i<<1|1);

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
           int x,y; double k; cin>>x>>y>>k;
           add_(x,y,k,1,n,1);
        }
        else if(op==2)
        {
            int x,y; cin>>x>>y;
            double ans1=query(sum1,x,y,1,n,1)/(y-x+1);
            printf("%.4lf\n",ans1);
        }
        else
        {
            int x,y; cin>>x>>y; int d=y-x+1;
            double p=query(sum1,x,y,1,n,1);
            double q=query(sum2,x,y,1,n,1);
            double ans2=q/d-(p/d)*(p/d);
            printf("%.4lf\n",ans2);
        }
    }
}


signed main()
{
    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}