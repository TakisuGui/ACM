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
    vector<int> cnt(n+1,0);
    vector<int> have(n+1,0);
    ll initial_sum=0; int h_max=-1;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i]; initial_sum+=a[i]*i;
        cnt[a[i]]++;
        h_max=max(h_max,a[i]);
    }

    have[n]=cnt[n];
    for(int i=n-1;i>=1;i--) have[i]=have[i+1]+cnt[i];


    ll remain=0;

    for(int i=1;i<=h_max;i++)
    {
        remain+=(ll)(n-have[i]+1+n)*(have[i])/2;
    }

    ll ans=remain-initial_sum;
    int gain=0;

    for(int i=1;i<=n;i++)  gain=max(gain,i-(n-have[a[i]]+1));
    
    cout<<(ll)ans+gain<<endl;
}



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}