#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

int a[N];

void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    if(n==1)
    {
        cout<<(a[1]==0 ? "Yes" : "No")<<endl;
        return;
    }

    bool pass=true;

    if(a[1]>a[2]||a[n]>a[n-1]) pass=false;

    for(int i=2;i<=n-1;i++) if(a[i]>a[i-1]&&a[i]>a[i+1]) pass=false;

    cout<<(pass ? "Yes" : "No")<<endl;
}

signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}