#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=2e5+10;

void solve()
{
    int n; cin>>n;
    vector<int> a;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int x; cin>>x; mp[x]++;

        if(x<=31622&&x!=1) a.push_back(x);
    }

    if(mp[1]>=2)
    {
        cout<<"YES"<<endl;
        return;
    }

    for(auto [k,v] : mp)
    {
        if(v>=2&&mp[1])
        {
            cout<<"YES"<<endl;
            return;
        }
    }

    for(auto v:a)
    {
        int x=v*v;
        for(int i=2;x<=1e9;i++,x*=v)
        {
            if(mp[i]&&mp[x])
            {
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    
    cout<<"NO"<<endl;
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