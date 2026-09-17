#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{   
    unordered_map<char,int> mp;
    string s; cin>>s;
    for(char c : s) mp[c]++;
    int ans=0;
    for(auto [key,cnt] : mp)
    {
        if(cnt==1) ans++;
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