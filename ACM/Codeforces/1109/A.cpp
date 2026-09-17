#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"


void solve()
{
    int n; cin>>n;
    string s; cin>>s;
    int max_s=0;
    int cur_s=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='#') cur_s++;
        else
        {
            max_s=max(max_s,cur_s);
            cur_s=0;
        }
    }
    max_s=max(max_s,cur_s);
    int ans=(max_s+1)/2;
    cout<<ans<<endl;
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