#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=3e5+10;
const int MOD=1e7+7;


void solve()
{
    int n,q,x; cin>>n>>q>>x;
    int sum=0;
    vector<int> a;
    for(int i=1;i<=n;i++)
    {
        int t; cin>>t;
        a.push_back(abs(t-x));
        sum+=abs(t-x);
    }

    sort(a.rbegin(),a.rend());
    vector<int> pre(n+3);
    pre[1]=a[0];

    for(int i=2;i<=n;i++)
    {
        pre[i]=pre[i-1]+a[i-1];
    }

    while(q--)
    {
        int k; cin>>k;
        if(k>=sum)
        {
            cout<<0<<endl;
            continue;
        }
        int goal=sum-k;

        int l=1,r=n,ans=n+1;
        while(l<=r)
        {
            int mid=(l+r)>>1;

            if(pre[mid]>=goal)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        cout<<ans<<endl;
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