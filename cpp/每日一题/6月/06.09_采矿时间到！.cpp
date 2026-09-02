#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6;


void solve()
{
    int n,h; cin>>n>>h;
    vector<string> s(6);
    for(int i=0;i<5;i++) cin>>s[i];

    int dex0=0,dex1=0,dex2=0;

    for(int j=0;j<n;j++)
    {
        int i=2;
        if(s[i-1][j]=='*'&&s[i-2][j]=='*') dex0++;
        else if(s[i-1][j]=='*'&&s[i-2][j]=='#') dex1++;
        else if(s[i-1][j]=='#'&&s[i-2][j]=='*') dex2++;

        if(s[i+1][j]=='*'&&s[i+2][j]=='*') dex0++;
        else if(s[i+1][j]=='*'&&s[i+2][j]=='#') dex1++;
        else if(s[i+1][j]=='#'&&s[i+2][j]=='*') dex2++;
    }

    int ans=0;

    int cnt0=(dex0==0 ? 0 : min(dex0,h/2) );
    ans+=cnt0*2;
    h-=cnt0*2;
    int cnt1=(dex1==0 ? 0 : min(dex1,h));
    h-=cnt1;
    ans+=cnt1;
    int cnt2=(dex2==0 ? 0 : min(dex2,h/2));
    ans+=cnt2;

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