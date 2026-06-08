#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

vector<int> a(N);
vector<int> d(N);

void solve()
{   
    int n,q; cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int i=1;i<=n-1;i++) 
    {
        d[i]=((a[i+1]-a[i])%5+5)%5;
        ans+=d[i];
    }

    while(q--)
    {
        int l,r; cin>>l>>r;
        if(l>1)
        {
           ans-=d[l-1];
           d[l-1]=(d[l-1]+1)%5;
           ans+=d[l-1];
        }
        if(r<n)
        {
            ans-=d[r];
            d[r]=((d[r]-1)%5+5)%5;
            ans+=d[r];
        }
        cout<<ans<<endl;
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