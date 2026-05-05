#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=1e9+10;

int f[6]={0,1,2,3,5};


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;cin>>t;


    while(t--)
    {
        ll x;cin>>x;
        ll group=(x-1)/5;
        ll dex=(x-1)%5;
        
        ll ans=group*6+f[dex];
        
        cout<<ans<<endl;
        
    }
    return 0;
    
}