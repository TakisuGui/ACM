#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=2e5+10;



void solve()
{
    vector<ll> dex2,dex3,dex6,dexelse;

    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;

        if(x%3==0&&x%2==0) dex6.push_back(x);
        else if(x%3==0&&x%2!=0) dex3.push_back(x);
        else if(x%3!=0&&x%2==0) dex2.push_back(x);
        else dexelse.push_back(x);
    }

    vector<ll> res;
    for(auto x:dex6) res.push_back(x);
    for(auto x:dex2) res.push_back(x);
    for(auto x:dexelse) res.push_back(x);
    for(auto x:dex3) res.push_back(x);

    for(int i = 0; i < n; i++)  cout<<res[i]<<(i==n-1 ? "" : " ");
    cout<<endl;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}