#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
void solve()
{
    int n;
    vector<int> d(n + 1);

    for(int i=1;i<=n;i++) cin>>d[i];
 
    int cur=0;
 
    for(int i=n;i>=1;i--) cur=min(cur+1,d[i]);
    
    int ans=min(n,cur + 1);
     
    cout<<ans<<"\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }

    return 0;
}