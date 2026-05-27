#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
    int n,m; cin>>n>>m;

    if(n>m) swap(n,m);

    if(n==m) cout<<"0";
    else if(m-1==n) cout<<"1";
    else
    {
        for(int i=n+1;i<m;i++) cout<<"9";
        for(int i=1;i<n;i++) cout<<"0";
        cout<<1;
    }
    cout<<" ";
    for(int i=n;i<m;i++) cout<<9;
    cout<<"8";
    for(int i=1;i<n;i++) cout<<9;
    cout<<endl;
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