#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
    int n; string s; cin>>n>>s;
    unordered_map<char,int> mp;

    for(auto c : s)
    {
        mp[c]++;
    }

    cout<<(mp['A']==mp['B']&&mp['B']==mp['C']&&mp['C']==mp['D'] ? "Yes" : "No")<<endl;
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