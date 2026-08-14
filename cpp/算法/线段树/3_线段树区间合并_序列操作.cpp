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
vector<int> lchange(N<<2);
vector<bool> update(N<<2);
vector<bool> reverse_(N<<2);

void up(int i,int ln,int rn)
{
    int l=i<<1,r=i<<1|1;
    sum[i]=sum[l]+sum[r];
    len0[i]=max({len0[l],len0[r],suf0[l]+pre0[r]});
    pre0[i]= len0[l]<ln ? pre0[l] : pre0[l]+pre0[r];
    suf0[i]= len0[r]<rn ? suf0[r] : suf0[r]+suf0[r];
    len1[i]=max({len1[l],len1[r],suf1[l]+pre1[r]});
    pre1[i]= len1[l]<ln ? pre1[l] : pre1[l]+pre1[r];
    suf1[i]= len1[r]<rn ? suf1[r] : suf1[r]+suf1[r];
}

void solve()
{

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