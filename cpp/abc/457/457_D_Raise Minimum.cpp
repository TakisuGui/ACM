#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6+10;

bool check(vector<int>& a,int n,int mid,int k)
{
    int total=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]<mid)
        {
            total+=(mid-a[i]+(i+1)-1)/(i+1);
            if(total>k) return false;
        }
    }
    return true;
}

void solve()
{
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int l=0,r=LONG_LONG_MAX; int ans;
    while(l<=r)
    {
        int mid=(l+r)/2;
        
        if(check(a,n,mid,k)) ans=mid,l=mid+1;
        else r=mid-1;
    }

    cout<<ans<<endl;
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