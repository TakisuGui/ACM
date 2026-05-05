#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;


void solve()
{
    string s; cin>>s;
    ll ans=0;

    for(int i=0,j=0;i<s.size();i++)
    {
        while(j<s.size()&&(j==i||s[j]!=s[j-1]))
        {
            j++;
        }
  
        ans+=(j-i);
        ans%=998244353;
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