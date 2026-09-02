#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6+10;


void solve()
{
    int n; cin>>n;
    vector<int> a(n); for(int i=0;i<n;i++) cin>>a[i];

    sort(a.begin(),a.end());

    vector<int> b;

    if(n%2==0)
    {
        for(int i=0;i<n/2;i++) b.push_back(a[i]*a[n-i-1]);
        sort(b.begin(),b.end());
        cout<<b[b.end()-b.begin()-1]-b[0]<<endl;
    }
    else 
    {
        b.push_back(a[n-1]);
        for(int i=0;i<n-1;i++) b.push_back(a[i]*a[n-i-2]);
        sort(b.begin(),b.end());
        cout<<b[b.end()-b.begin()-1]-b[0]<<endl;
    }
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