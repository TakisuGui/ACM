#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e9+7;


void solve()
{
    int n,k; cin>>n>>k;
    vector<int> a(n); 
    int sum=0;
    for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];

    if(k==1)
    {
        cout<<sum<<endl;
        return;
    }

    sort(a.begin(),a.end());
    ll max_sum=-4e18;
    vector<int> pre(n+1,0);
    for(int i=0;i<n;i++) pre[i+1]=pre[i]+a[i];

    auto get_sum=[&](int l,int r)
    {
        return pre[r+1]-pre[l];
    };

    if(k%2==1)
    {
        int left=k/2,right=k/2;
        for(int i=left;i+right<n;i++)
        {
            int t_sum=sum;
            t_sum-=(get_sum(0,left-1)+get_sum(i+1,i+right)+a[i]);
            t_sum+=k*a[i];

            max_sum=max(max_sum,t_sum);
        }
    }
    else
    {
        int left=k/2-1,right=k/2-1;
        for(int i=left;i+1+right<n;i++)
        {
            int t_sum=sum;
            t_sum-=(get_sum(0,left-1)+get_sum(i+2,i+1+right)+a[i]+a[i+1]);
            t_sum+=(k/2)*(a[i]+a[i+1]);

            max_sum=max(max_sum,t_sum);
        }
    }

    cout<<max_sum<<endl;
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
