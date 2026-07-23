#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e9+7;

int get_layer(int x)
{
    int l=1,r=2e9;
    int ans=2e9+1;
    
    while(l<=r)
    {
        int mid=(l+r)/2;
        int cur=mid*(mid+1)/2;

        if(cur>=x)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }

    return ans;
}

void solve()
{
    int n,l,r; cin>>n>>l>>r;

    cout<<(l+get_layer(l)>r ? "Yes" : "No")<<endl;
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
