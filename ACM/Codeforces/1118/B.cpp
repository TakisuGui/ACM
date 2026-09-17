#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e7+7;


void solve()
{
    int n,m; cin>>n>>m;
    vector<int> a(n);
    vector<int> cnt(m+1,0);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    vector<int> pre(m+1,0);
    for (int i=1;i<=m;i++) pre[i]=pre[i-1]+cnt[i];

    int sum_a=0;
    int max_a=0;
    for(int i=0;i<n;i++)
    {
        sum_a+=a[i];
        max_a=max(max_a,a[i]);
    }
    vector<int> ans(m+1,sum_a);

    int K0=0;
    int pw=1;
    while(pw<max_a)
    {
        pw<<=1;
        K0++;
    }
    K0=max(K0,1ll);
    int kmax=min(m,K0);

    for(int k=1;k<=kmax;k++)
    {
        int T=(1ll<<k)-1;
        int p2=(1ll<<k);
        int best=0;

        for(int l=1;l<=m;l++)
        {
            int s=0;
            int jmax=min(T,m/l);
            for(int j=1;j<=jmax;j++)
            {
                s+=n-pre[j*l-1];
            }
            if(p2*l<=m) s+=cnt[p2*l];
            best=max(best,s);
        }
        ans[k]=best;
    }

    for(int k=1;k<=m;k++) cout<<ans[k]<<" ";
    cout<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}