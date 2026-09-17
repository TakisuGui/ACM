#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e7+7;


void solve()
{
    int n; cin>>n;
    string a,b; cin>>a>>b;

    vector<int> odd_a,odd_b,even_a,even_b;

    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            if(a[i]=='1') even_a.push_back(i);
            if(b[i]=='1') even_b.push_back(i);
        }
        else
        {
            if(a[i]=='1') odd_a.push_back(i);
            if(b[i]=='1') odd_b.push_back(i);
        }
    }

    if(odd_a.size()!=odd_b.size()||even_b.size()!=even_a.size())
    {
        cout<<-1<<endl;
        return;
    }

    int ans=0;
    for(int i=0;i<odd_a.size();i++)
    {
        ans+=abs(odd_a[i]-odd_b[i])/2;
    }
    for(int i=0;i<even_a.size();i++)
    {
        ans+=abs(even_a[i]-even_b[i])/2;
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