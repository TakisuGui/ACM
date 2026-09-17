#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=300000*31+5;

int tree[N][2];
vector<int> node_dex[N];
int cnt=1;
int high;
ll sum_inv[32][2];

void insert_(int x,int idx)
{
    int cur=1;
    node_dex[cur].push_back(idx);
    for(int i=high;i>=0;i--)
    {
        int j=(x>>i)&1;
        if(tree[cur][j]==0) tree[cur][j]=++cnt;
        cur=tree[cur][j];
        node_dex[cur].push_back(idx);
    }
}

void dfs(int cur,int bit)
{
    if(cur==0||bit<0) return;
    int left=tree[cur][0];
    int right=tree[cur][1];

    if(left&&right)
    {
        const auto& vec0=node_dex[left];
        const auto& vec1=node_dex[right];

        int p0=0,p1=0;
        int sz0=vec0.size(),sz1=vec1.size();
        ll inv0=0;
        ll inv1=0;

        while(p0<sz0&&p1<sz1)
        {
            if(vec0[p0]<vec1[p1])
            {
                inv0+=(sz1-p1);
                p0++;
            }
            else
            {
                inv1+=(sz0-p0);
                p1++;
            }
        }
        sum_inv[bit][0]+=inv0;
        sum_inv[bit][1]+=inv1;
    }

    dfs(left,bit-1);
    dfs(right,bit-1);
}

void solve()
{
    int n; cin>>n; int max_=0;
    memset(sum_inv,0,sizeof(sum_inv));
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i],max_=max(max_,a[i]);

    if(max_!=0) high=31-__builtin_clz(max_);
    else high=0;

    for(int i=1;i<=n;i++) insert_(a[i],i);

    dfs(1,high);

    ll ans=0,v=0;
    for(int i=high;i>=0;i--)
    {
        if(sum_inv[i][1]>sum_inv[i][0])
        {
            v|=(1LL<<i);
            ans+=sum_inv[i][0];
        }
        else ans+=sum_inv[i][1];
    }
    cout<<ans<<" "<<v<<endl;
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