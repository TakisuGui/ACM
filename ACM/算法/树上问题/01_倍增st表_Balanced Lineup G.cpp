#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=5e4+10;
const int MOD=1e7+7;
const int LIMIT=16;

vector<vector<int>> st_max(N<<1,vector<int>(LIMIT));
vector<vector<int>> st_min(N<<1,vector<int>(LIMIT));
vector<int> a(N);
vector<int> log2_(N);
int n,m; 
int power;

void build(int n)
{
    log2_[0]=-1;
    for(int i=1;i<=n;i++)
    {
        log2_[i]=log2_[i>>1]+1;
        st_max[i][0]=a[i];
        st_min[i][0]=a[i];
    }

    for(int p=1;p<=log2_[n];p++)
    {
        for(int i=1;i+(1<<p)-1<=n;i++)
        {
            st_max[i][p]=max(st_max[i][p-1],st_max[i+(1<<(p-1))][p-1]);
            st_min[i][p]=min(st_min[i][p-1],st_min[i+(1<<(p-1))][p-1]);
        }
    }

}

int query(int l,int r)
{
    int p=log2_[r-l+1];
    int x=max(st_max[l][p],st_max[r-(1<<p)+1][p]);
    int y=min(st_min[l][p],st_min[r-(1<<p)+1][p]);
    return x-y;
}

void solve()
{
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(n);

    while(q--)
    {
        int a,b; cin>>a>>b;
        cout<<query(a,b)<<endl;
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