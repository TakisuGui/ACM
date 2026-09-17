#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e9+7;

void solve()
{
    int n,m; cin>>n>>m;
    vector<vector<ll>> a(n,vector<ll>(m));
    ll sum=0; ll max_a=-2e18;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            sum+=a[i][j];
            max_a=max(max_a,a[i][j]);
        }
    }

    vector<vector<ll>> dp_min(n,vector<ll>(m));
    vector<vector<ll>> dp_max(n,vector<ll>(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0&&j==0) dp_max[i][j]=dp_min[i][j]=a[0][0];
            else if(i==0) 
            {
                dp_min[i][j]=dp_min[i][j-1]+a[i][j];
                dp_max[i][j]=dp_max[i][j-1]+a[i][j];
            }
            else if(j==0) 
            {
                dp_min[i][j]=dp_min[i-1][j]+a[i][j];
                dp_max[i][j]=dp_max[i-1][j]+a[i][j];
            }
            else
            {
                dp_min[i][j]=a[i][j]+min(dp_min[i-1][j],dp_min[i][j-1]);
                dp_max[i][j]=a[i][j]+max(dp_max[i-1][j],dp_max[i][j-1]);
            }
        }
    }

     
    ll min_p=dp_min[n-1][m-1];
    ll max_p=dp_max[n-1][m-1];
    ll L=n+m-1; 
    ll N=(ll)n*m;
    
    if(min_p!=max_p) 
    {
        cout<<-1<<endl;
        return;
    }
    
    ll A=L*L-N;
    ll B=L*min_p-sum;
    
    if(A==0) 
    {
        if(B!=0) 
        {
            cout<<-1<<endl;
            return;
        }
        if(max_a*N-sum<0) 
        {
            cout<<-1<<endl;
            return;
        }
        ll x=max_a;
        ll k=(N*x-sum)/L;
        cout<<k<<endl;
        return;
    }
    
    if(B%A!=0) 
    {
        cout<<-1<<endl;
        return;
    }
    
    ll x=B/A;
    if(x<max_a) 
    {
        cout<<-1<<endl;
        return;
    }
    
    ll k=(N*x-sum)/L;
    if(k<0) 
    {
        cout<<-1<<endl;
        return;
    }
    
    cout<<k<<endl;
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
