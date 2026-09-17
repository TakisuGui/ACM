#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;

#define lc p<<1
#define rc p<<1|1

int n,m;
ll a[N];

struct node
{
    int l,r;
    ll sum,add;
}tr[N*4];

void lazy(int p,ll k)
{
    tr[p].sum+=(tr[p].r-tr[p].l+1)*k;
    tr[p].add+=k;
}

void pushup(int p)
{
    tr[p].sum=tr[lc].sum+tr[rc].sum;
}

void pushdown(int p)
{
    if(tr[p].add)
    {
        lazy(lc,tr[p].add);
        lazy(rc,tr[p].add);
        tr[p].add=0;
    }
}

void build(int p,int l,int r)
{
    tr[p]={l,r,a[l],0};
    if(l==r) return;

    int mid=(l+r)>>1;
    build(lc,l,mid); build(rc,mid+1,r);
    pushup(p);
}

void modify(int p,int x,int y,ll k)
{
    int l=tr[p].l,r=tr[p].r;
    if(x<=l&&r<=y)
    {
        lazy(p,k);
        return;
    }

    pushdown(p);
    int mid=(l+r)>>1;
    if(x<=mid) modify(lc,x,y,k);
    if(y>mid)  modify(rc,x,y,k);
    pushup(p);
}

ll query(int p,int x,int y)
{
    int l=tr[p].l,r=tr[p].r;
    if(x<=l&&r<=y) return tr[p].sum;

    pushdown(p);
    int mid=(l+r)>>1;
    ll sum=0;
    if(x<=mid) sum+=query(lc,x,y);
    if(y>mid)  sum+=query(rc,x,y);

    return sum;
}



int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];

    build(1,1,n);

    while(m--)
    {
        int op,x,y; cin>>op>>x>>y;
        ll k;
        if(op==1)
        {
            cin>>k;
            modify(1,x,y,k);
        }
        else cout<<query(1,x,y)<<endl;
    }
    
    return 0;
}