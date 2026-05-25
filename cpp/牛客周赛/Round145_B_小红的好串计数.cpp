#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{   
    int n; cin>>n;
    string s; cin>>s;
    
    int ans=n*(n+1)/2;
    char cur=s[0]; int has=1;
    for(int i=1;i<n;i++)
    {
        if(s[i]==cur) has++;
        else
        {
            ans-=has*(has+1)/2;
            has=1;
            cur=s[i];
        }
    }

    ans-=has*(has+1)/2;

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