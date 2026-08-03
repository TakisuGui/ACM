#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e7+7;

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n,q; cin>>n>>q;
    vector<ull> has(125001);
    for(int i=1;i<=125000;i++) has[i]=rnd();

    vector<ull> tar_pre(n+1,0);
    for(int i=1;i<=n/2;i++) tar_pre[i]=tar_pre[i-1]+has[i]*2;
    
    vector<ull> pre(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        if(x>n/2) pre[i]=pre[i-1];
        else pre[i]=pre[i-1]+has[x];
    }

    while(q--)
    {
        int l,r; cin>>l>>r;
        int len=r-l+1;

        if(len%2!=0)
        {
            cout<<"No"<<endl;
            continue;
        }

        int k=len/2;
        ull cur_pre=pre[r]-pre[l-1];

        cout<<(cur_pre==tar_pre[k] ? "Yes" : "No")<<endl;
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