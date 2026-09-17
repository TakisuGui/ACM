#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=998244353;

void solve()
{
    int n,k; cin>>n>>k;
    if(k<n||k>2*n-1)
    {
        cout<<-1<<endl;
        return;
    }

    int m=2*n-k;
    vector<vector<int>> a(n,vector<int>(n,0));

    for(int i=0;i<m;i++) a[i][i]=i+1;
    for(int t=0;t<n-m;t++) a[m+t][0]=m+1+t;
    for(int t=0;t<n-m;t++) a[0][m+t]=n+1+t;

    int cur=k+1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==0) a[i][j]=cur++;
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
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