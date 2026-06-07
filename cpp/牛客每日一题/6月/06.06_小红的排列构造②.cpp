#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6;


void solve()
{
    int n; cin>>n;
    string s; cin>>s; s=" "+s;
    int pass=1;
    int cur=1;
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1')
        {
            for(int j=pass,have=cur;have>=1;j--,have--) ans.push_back(j);
            cur=1;
            pass++;
        }
        else
        {
            pass++;
            cur++;
        }
    }

    if(cur>1)
    {
        for(int j=pass,have=cur;have>=1;j--,have--) ans.push_back(j);
    }

    if(ans.size()!=n) cout<<-1<<endl;
    else 
    {
        for(int i=0;i<n;i++) cout<<ans[i] <<" ";
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