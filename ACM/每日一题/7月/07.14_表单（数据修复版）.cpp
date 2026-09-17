#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"


void solve()
{
    int n,m; cin>>n>>m;
    int ans=0;
    unordered_map<string,bool> mp;
    for(int i=0;i<n;i++)
    {
        string s; cin>>s;
        if(mp[s]==false) mp[s]=true;
        else ans++;
    }


    for(int i=0;i<m;i++)
    {
        int x; cin>>x;
        if(x==1)
        {
            string plus; cin>>plus;
            if(mp[plus]==false) mp[plus]=true;
            else ans++;
        }
        else
        {
            cout<<ans<<endl;
            ans=0;
        }
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