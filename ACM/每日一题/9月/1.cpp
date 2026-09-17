#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e18;
const int MOD=998244353;

void solve()
{
    int n; cin>>n;
    vector<bool> a_vis(n+1,false);
    vector<bool> b_vis(n+1,false);
    vector<int> a(n+1,-1),b(n+1,-1);

    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        if(!a_vis[x])
        {
            a_vis[x]=true;
            a[i]=x;
        }
        else if(a_vis[x]&&!b_vis[x])
        {
            b_vis[x]=true;
            b[i]=x;
        }
        else
        {
            cout<<-1<<endl;
            return;
        }
    }

    int k=1;
    for(int i=1;i<=n;i++) 
    {
        if(a_vis[i]) continue;

        while(a[k]!=-1) k++;
        a[k++]=i;
    }
    k=1;
    for(int i=1;i<=n;i++) 
    {
        if(b_vis[i]) continue;

        while(b[k]!=-1) k++;
        b[k++]=i;
    }

    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++) cout<<b[i]<<" ";
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