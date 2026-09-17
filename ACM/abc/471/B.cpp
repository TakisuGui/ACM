#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
const int N=2e5;
const int MOD=1e7+7;



void solve()
{
    int n; cin>>n;
    map<string,int> mp;

    for(int i=1;i<=n;i++)
    {
        string s; cin>>s;
        for(char &c : s) c=tolower(c);
        
        mp[s]++;
    }

    int max_=-1;
    for(auto& [key,v] : mp) max_=max(max_,v);
    cout<<max_<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}