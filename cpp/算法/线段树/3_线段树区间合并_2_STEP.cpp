#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
const int N=2e5+10;
const int MOD=1e7+7;
const int INF=1e18;

vector<int> a(N);
vector<int> len(N<<2);
vector<int> pre(N<<2);
vector<int> suf(N<<2);

void up(int i,int l,int r)
{
    len[i]=max(len[i<<1],len[i<<1|1]);
    pre[i]=pre[i<<1];
    suf[i]=suf[i<<1|1];
    int mid=(l+r)>>1,ln=mid-l+1,rn=r-mid;

    if(a[mid]!=a[mid+1]) 
    {
        len[i]=max(len[i],suf[i<<1]+pre[i<<1|1]);

        if(pre[i<<1]==ln) pre[i]=pre[i<<1]+pre[i<<1|1];
        if(suf[i<<1|1]==rn) suf[i]=suf[i<<1]+suf[i<<1|1];
    }

}

void build(int i,int l,int r)
{
    if(l==r)  len[i]=pre[i]=suf[i]=1;
    else
    {
        int mid=(l+r)>>1;
        build(i<<1,l,mid);
        build(i<<1|1,mid+1,r);
        up(i,l,r);
    }
}


void reverse_(int jobi,int l,int r,int i)
{
    if(l==r) a[jobi]^=1;
    else
    {
        int mid=(l+r)>>1;
        if(jobi<=mid) reverse_(jobi,l,mid,i<<1);
        else reverse_(jobi,mid+1,r,i<<1|1);

        up(i,l,r);
    } 
}


void solve()
{
    int n,q; cin>>n>>q;
    build(1,1,n);

    while(q--)
    {
        int x; cin>>x;
        reverse_(x,1,n,1);
        cout<<len[1]<<endl;
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