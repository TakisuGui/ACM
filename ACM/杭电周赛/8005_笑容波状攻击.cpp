#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
    string s; cin>>s;
    int n=s.size();
    int total=(n+1)*n/2;

    int cnt=0;

    ll only_zero=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0') cnt++;
        else
        {
            only_zero+=(cnt+1)*cnt/2;
            cnt=0;
        }
    }
    only_zero+=cnt*(cnt+1)/2;

    cnt=0;

    ll only_one=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1') cnt++;
        else
        {
            only_one+=(cnt+1)*cnt/2;
            cnt=0;
        }
    }
    only_one+=cnt*(cnt+1)/2;

    cout<<2*(total-only_one-only_zero)+only_zero<<endl;
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