#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6+10;

int m,n;

void solve()
{
    string s; cin>>s;
    int ans=0;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='c') ans+=min(i,(int)s.size()-(i+1))+1;
    }

    cout<<ans<<endl;
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