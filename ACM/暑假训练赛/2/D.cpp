#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=3e5+10;
const int INF=1e18;

int n,cnt,d;
vector<int> a(N);
vector<int> temp(N);
vector<int> tree(N);
vector<int> has(N);
vector<int> min_(N<<2);

vector<int> L_bound(N);
vector<int> R_bound(N);
vector<int> ans_(N);

int lowbit(int x)
{
    return x&(-x);
}
void add(int i,int v)
{
    while(i<=cnt)
    {
        tree[i]+=v;
        i+=lowbit(i);
    }
}
int sum(int i)
{
    int ans=0;
    while(i>0)
    {
        ans+=tree[i];
        i-=lowbit(i);
    }
    return ans;
}
int range_sum(int l,int r)
{
    return sum(r)-sum(l-1);
}


void up(int i)
{
    min_[i]=min(min_[i<<1],min_[i<<1|1]);
}
void build(int l,int r,int i)
{
    if (l==r) min_[i]=INF;
    else
    {
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
        up(i);
    }
}
void update_(int jobi,int v,int l,int r,int i)
{
    if(l==r) min_[i]=min(min_[i],v);
    else
    {
        int mid=(l+r)>>1;
        if (jobi<=mid) update_(jobi,v,l,mid,i<<1);
        else update_(jobi,v,mid+1,r,i<<1|1);
        up(i);
    }
}
int query(int jobl,int jobr,int l,int r,int i)
{
    if(jobl>r || jobr<l) return INF;
    if(jobl<=l&&r<=jobr) return min_[i];

    int mid=(l+r)>>1;
    int ans=INF;
    if(jobl<=mid) ans=min(ans,query(jobl,jobr,l,mid,i<<1));
    if(jobr>mid) ans=min(ans,query(jobl,jobr,mid+1,r,i<<1|1));

    return ans;
}


int find_(int v)
{
    int l=1,r=cnt,ans=cnt+1;
    while(l<=r)
    {
        int mid=(l+r)>>1;

        if(has[mid]>=v)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}
int find_upper(int v)
{
    int l=1,r=cnt,ans=cnt+1;
    while(l<=r)
    {
        int mid=(l+r)>>1;

        if(has[mid]>v)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}



void solve()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    temp=a;

    sort(temp.begin()+1,temp.begin()+n+1);
    has[1]=temp[1];
    cnt=1;

    for(int i=2;i<=n;i++)
    {
        if(temp[i]!=has[cnt]) has[++cnt]=temp[i];
    }

    for (int i=1; i<=cnt;i++) tree[i]=0;
    build(1,cnt,1);

    for(int i=n;i>=1;i--)
    {
        int jL=INF;
        int l1=find_(a[i]-d),l2=find_upper(a[i]-1)-1;
        if(l1<=l2) jL=query(l1,l2,1,cnt,1);

        int jR=INF;
        int r1=find_(a[i]),r2=find_upper(a[i]+d)-1;
        if(r1<=r2) jR=query(r1,r2,1,cnt,1);
        
        L_bound[i]=a[i];
        R_bound[i]=a[i];

        if (jL!=INF) 
        {
            L_bound[i]=min(L_bound[i],L_bound[jL]);
            R_bound[i]=max(R_bound[i],R_bound[jL]);
        }
        if (jR!=INF) 
        {
            L_bound[i]=min(L_bound[i],L_bound[jR]);
            R_bound[i]=max(R_bound[i],R_bound[jR]);
        }

        int pos=find_(a[i]);
        update_(pos,i,1,cnt,1);
        add(pos,1);

        int ql=find_(L_bound[i]);
        int qr=find_upper(R_bound[i])-1;

        ans_[i]=range_sum(ql, qr);
    }
    for(int i=1;i<=n;i++) cout<<ans_[i]<<" ";
    cout<<endl;
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




