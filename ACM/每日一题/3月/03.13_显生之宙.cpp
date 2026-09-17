#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void slove()
{
    int n; cin>>n;

    ll a[n+2]; a[0]=0; 
    for(int i=1;i<=n;i++) cin>>a[i];

    sort(a+1,a+n+1);

    if(a[1] >= 0) {
        ll sum = 0;
        for(int i=1;i<=n;i++) sum += a[i];
        cout << sum << endl;
        return;
    }
    
    ll real[n+2]; 
    ll p = 0;    
    int flag = 1;
    int first_pos = n;
    
    real[1] = a[1];
    
    for(int i=2;i<=n;i++)
    {
        if(flag) p = p + real[i-1];

        real[i] = a[i] + p;
        
      
        if(real[i] >= 0 && flag) {
            first_pos = i;
            flag = 0;
        }
    }
    
    ll ans = 0;
    for(int i=first_pos;i<=n;i++) ans += real[i];
    cout << ans << endl;
}

int main()
{
    int t; cin>>t;
    while(t--) slove();
    return 0;
}