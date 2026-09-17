#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;
const int MOD=998244353;

void solve()
{   
    int n; cin>>n;
    unordered_map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        mp[x]++;
    }

    bool pass=false;
    for(auto[key,cnt]: mp)
    {
        if(cnt%2!=0)
        {
            pass=true;
            break;
        }
    }

    cout<<(pass ? "red" : "fang")<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}