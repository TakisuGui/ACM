#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6+10;


void solve()
{
    int n,k; cin>>n>>k;
    vector<vector<int>> a(n);

    for(int i=0;i<n;i++)
    {
        int x; cin>>x;
        a[i].resize(x);
        for(int j=0;j<x;j++) cin>>a[i][j];
    }

    vector<int> c(n);
    for(int i=0;i<n;i++) cin>>c[i];

    ll total=0;
    int idx=-1;
    int off=0;

    for(int i=0;i<n;i++)
    {
        int len=c[i]*a[i].size();
        if(k>total&&k<=total+len)
        {
            idx=i;
            off=k-total-1;
            break;
        }
        total+=len;
    }

    int pos=off%a[idx].size();
    cout<<a[idx][pos]<<endl;
}


signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}