#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int N=2e5+10;
typedef long long ll;
ll f[N];

void init()
{
    f[0]=1;
    for(int i=1;i<N;i++)
    {
        f[i]=f[i-1]*i%MOD;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;cin>>t;
    init();
    while(t--)
    {
        int n;cin>>n;
        int a[n+3],b[n+3];
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        
        int big=0;
        for(int j=n;j>=1;j--)
        {
            if(a[j]<b[1]) break;
            
            big++;
        }
        
        ll ans=0;
        
        ans=f[big]*f[n-big]%MOD;
        
        cout<<ans<<endl;
    }
    
    return 0;
    
}