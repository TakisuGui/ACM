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
vector<int> sum(4*N);
vector<int> len0(N<<2);
vector<int> pre0(N<<2);
vector<int> suf0(N<<2);
vector<int> len1(N<<2);
vector<int> pre1(N<<2);
vector<int> suf1(N<<2);
vector<int> change(N<<2);
vector<bool> update(N<<2);
vector<bool> reverse_(N<<2);

void up(int i,int ln,int rn)
{
    int l=i<<1,r=i<<1|1;
    sum[i]=sum[l]+sum[r];
    len0[i]=max({len0[l],len0[r],suf0[l]+pre0[r]});
    pre0[i]= len0[l]<ln ? pre0[l] : pre0[l]+pre0[r];
    suf0[i]= len0[r]<rn ? suf0[r] : suf0[l]+suf0[r];
    len1[i]=max({len1[l],len1[r],suf1[l]+pre1[r]});
    pre1[i]= len1[l]<ln ? pre1[l] : pre1[l]+pre1[r];
    suf1[i]= len1[r]<rn ? suf1[r] : suf1[l]+suf1[r];
}

void updatelazy(int i,int v,int n)
{
    sum[i]=v*n;
    len0[i]=pre0[i]=suf0[i]= v==0 ? n : 0;
    len1[i]=pre1[i]=suf1[i]= v==1 ? n : 0;
    reverse_[i]=false;
    update[i]=true;
    change[i]=v;
}

void reverselazy(int i,int n)
{
    int tmp;
    sum[i]=n-sum[i];
    tmp=len0[i]; len0[i]=len1[i]; len1[i]=tmp;
    tmp=pre0[i]; pre0[i]=pre1[i]; pre1[i]=tmp;
    tmp=suf0[i]; suf0[i]=suf1[i]; suf1[i]=tmp;
    reverse_[i]=!reverse_[i];
} 

void down(int i,int ln,int rn)
{
    if(update[i])
    {
        updatelazy(i<<1,change[i],ln);
        updatelazy(i<<1|1,change[i],rn);
        update[i]=false;
    }
    if(reverse_[i])
    {
        reverselazy(i<<1,ln);
        reverselazy(i<<1|1,rn);
        reverse_[i]=false;
    }
}


void build(int l,int r,int i)
{
    if(l==r)
    {
        sum[i]=a[l];
        update[i]=false;
        reverse_[i]=false;
        len0[i]=pre0[i]=suf0[i]= a[l]==0 ? 1 : 0;
        len1[i]=pre1[i]=suf1[i]= a[l]==1 ? 1 : 0;
    }
    else
    {
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
        up(i,mid-l+1,r-mid);
    }
    update[i]=false;
    reverse_[i]=false;
}


void update_(int jobl,int jobr,int v,int l,int r,int i)
{
    if(jobl<=l&&r<=jobr) updatelazy(i,v,r-l+1);
    else
    {
        int mid=(l+r)>>1;
        down(i,mid-l+1,r-mid);

        if(jobl<=mid) update_(jobl,jobr,v,l,mid,i<<1);
        if(jobr>mid) update_(jobl,jobr,v,mid+1,r,i<<1|1);
        up(i,mid-l+1,r-mid);
    }
}

void to_reverse(int jobl,int jobr,int l,int r,int i)
{
    if(jobl<=l&&r<=jobr) reverselazy(i,r-l+1);
    else
    {
        int mid=(l+r)>>1;
        down(i,mid-l+1,r-mid);

        if(jobl<=mid) to_reverse(jobl,jobr,l,mid,i<<1);
        if(jobr>mid) to_reverse(jobl,jobr,mid+1,r,i<<1|1);
        up(i,mid-l+1,r-mid);
    }
}


int querysum(int jobl,int jobr,int l,int r,int i)
{
    if(jobl<=l&&r<=jobr) return sum[i];
    else
    {
        int mid=(l+r)>>1;
        down(i,mid-l+1,r-mid);

        int ans=0;
        if(jobl<=mid) ans+=querysum(jobl,jobr,l,mid,i<<1);
        if(jobr>mid) ans+=querysum(jobl,jobr,mid+1,r,i<<1|1);
        return ans;
    }
}


// 返回一个长度为3的数组ans，代表结果，具体含义如下：
// ans[0] : 线段树范围l~r上，被jobl~jobr影响的区域里，连续1的最长子串长度
// ans[1] : 线段树范围l~r上，被jobl~jobr影响的区域里，连续1的最长前缀长度
// ans[2] : 线段树范围l~r上，被jobl~jobr影响的区域里，连续1的最长后缀长度
vector<int> querylong(int jobl,int jobr,int l,int r,int i)
{
    if(jobl<=l&&r<=jobr) return {len1[i],pre1[i],suf1[i]};
    else
    {
        int mid=(l+r)>>1;
        down(i,mid-l+1,r-mid);

        if(jobr<=mid) return querylong(jobl,jobr,l,mid,i<<1);
        if(jobl>mid) return querylong(jobl,jobr,mid+1,r,i<<1|1);

        vector<int> l3=querylong(jobl,jobr,l,mid,i<<1);
        vector<int> r3=querylong(jobl,jobr,mid+1,r,i<<1|1);
        int llen=l3[0],lpre=l3[1],lsuf=l3[2];
		int rlen=r3[0],rpre=r3[1],rsuf=r3[2];

        int len=max({llen,rlen,lsuf+rpre});
        int pre= llen < mid-max(jobl,l)+1 ? lpre : (lpre+rpre);
        int suf= rlen < min(r,jobr)-mid ? rsuf : (lsuf+rsuf);
        return {len,pre,suf};
    }
}


void solve()
{
    int n,m; cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,n,1);

    while(m--)
    {
        int op,x,y; cin>>op>>x>>y; 
        x++; y++;

        if(op==0) update_(x,y,0,1,n,1);
        else if(op==1) update_(x,y,1,1,n,1);
        else if(op==2) to_reverse(x,y,1,n,1);
        else if(op==3) cout<<querysum(x,y,1,n,1)<<endl;
        else
        {
            vector<int> ans=querylong(x,y,1,n,1);
            cout<<ans[0]<<endl;
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