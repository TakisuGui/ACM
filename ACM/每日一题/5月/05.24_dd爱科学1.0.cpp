#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
    int n; string s; cin>>n>>s;
    
    string ans="";

    for(char c : s)
    {
        auto it=upper_bound(ans.begin(),ans.end(),c);
        if(it==ans.end()) ans.push_back(c);
        else *it=c;
    }

    cout<<n-ans.size()<<endl;
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