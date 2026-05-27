#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=5e5+10;

int a[N];

void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0; int j=1;
    
    for(int i=1;i<=n;i++)
    {
        if(a[i]%j==0)
        {
            ans++;
            j++;
        }
    }

    cout<<ans<<endl;
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