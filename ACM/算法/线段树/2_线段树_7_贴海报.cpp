#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e3+10;
const int MOD=1e7+7;
const int INF=1e18;

int n,m;
vector<int> pl(N);
vector<int> pr(N);
vector<int> num(4*N);
vector<int> has(4*N);
vector<int> posters(N<<4);
vector<bool> used(N);

int find_(int l,int r,int v)
{
    int ans=0;
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


void down(int i)
{
    if(posters[i])
    {
        posters[i<<1]=posters[i];
        posters[i<<1|1]=posters[i];
        posters[i]=0;
    }
}

void build(int l,int r,int i)
{
    if(l<r)
    {
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
    }
    posters[i]=0;
}

void update(int jobl,int jobr,int v,int l,int r,int i)
{
    if(jobl<=l&&r<=jobr) posters[i]=v;
    else
    {
        down(i);
        int mid=(l+r)>>1;
        if(jobl<=mid) update(jobl,jobr,v,l,mid,i<<1);
        if(jobr>mid) update(jobl,jobr,v,mid+1,r,i<<1|1);
    }
}


int query(int jobl,int jobr,int l,int r,int i)
{
    if(l==r)
    {
        if(posters[i]!=0&&!used[posters[i]])
        {
            used[posters[i]]=true;
            return 1;
        }
        else return 0;
    }
    else
    {
        down(i);
        int ans=0;
        int mid=(l+r)>>1;

        if(jobl<=mid) ans+=query(jobl,jobr,l,mid,i<<1);
        if(jobr>mid) ans+=query(jobl,jobr,mid+1,r,i<<1|1);

        return ans;
    }
}

void solve()
{
    cin>>n>>m;
    int size=0;
    num[++size]=n;
    for(int i=1;i<=m;i++) 
    {
        cin>>pl[i]>>pr[i];
        num[++size]=pl[i];
        num[++size]=pr[i];
    }

    sort(num.begin()+1,num.begin()+1+size);
    has[1]=num[1];
    int cnt=1;
    for(int i=2;i<=size;i++)
    {
        if(has[cnt]!=num[i]) has[++cnt]=num[i];
    }
    int p=cnt;
    for(int i=2;i<=p;i++)
    {
        if(has[i-1]+1<has[i]) has[++cnt]=has[i-1]+1;
    }
    sort(has.begin()+1,has.begin()+1+cnt);

    build(1,cnt,1);

    for(int i=1;i<=m;i++)
    {
        int jobl=find_(1,cnt,pl[i]);
        int jobr=find_(1,cnt,pr[i]);
        update(jobl,jobr,i,1,cnt,1);
    }

    cout<<query(1,find_(1,cnt,n),1,cnt,1)<<endl;
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