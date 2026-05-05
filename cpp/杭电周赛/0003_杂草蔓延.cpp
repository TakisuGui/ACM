#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n,m;
    cin>>n>>m;
    ll ans=(n+m+1)/2;
    cout<<ans<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if(cin>>t)
    {
        while(t--)
        {
            solve();
        }
    }
    return 0;
}