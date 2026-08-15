#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
const int MOD=1e7+7;


void solve()
{
    string s; cin>>s;
    int ans=0;
    int last_one=-1;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            int cnt_zero=i-last_one-1;
            int val=0;

            for(int j=i;j<min((int)s.size(),i+18);j++)
            {
                val=val<<1|(s[j]-'0');
                int len=j-i+1;

                if(len<=val&&val<=len+cnt_zero) ans++;
            }
            last_one=i;
        }
    }
    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}