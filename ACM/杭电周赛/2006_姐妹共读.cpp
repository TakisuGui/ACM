#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int n; cin>>n;
    unordered_map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        mp[x]++;
    }
    int ans=0;
    for(auto u:mp)
    {
        if(u.first<=n) ans++;
    }
    cout<<ans<<"\n";
}

int main()
{
    int size(256<<20);  // 256M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
    exit(0);
}