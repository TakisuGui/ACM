#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;

void solve()
{
    int x,y; cin>>x>>y;
    int ans=0;
    for(int i=0;i<=31;i++)
    {
        int a=x>>i;
        for(int j=0;j<=31;j++)
        {
            int b=y>>j;
            ans=max(ans,a^b);
        }
    }
    cout<<ans<<endl;
}


int main()
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