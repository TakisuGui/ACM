#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6;


void solve()
{
    map<string,string> mp;
    for(int i=1;i<=3;i++)
    {
        string a,b; cin>>a>>b;
        mp[b]=a;
    }

    int n; cin>>n;
    while(n--)
    {
        string s; cin>>s;
        if(mp.find(s)==mp.end()) cout<<"Fake"<<endl;
        else cout<<mp[s]<<endl;
    }
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