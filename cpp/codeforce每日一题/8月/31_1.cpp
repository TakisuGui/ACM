#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e18;
const int MOD=998244353;

struct Stone
{
    int height; 
    int id;    
};


void solve()
{
    int n; cin>>n;
    map<pair<int,int>,Stone> mp;
    int ans_r=-1;vector<int> ans_id;

    for(int i=1;i<=n;i++)
    {
        vector<int> a(3); cin>>a[0]>>a[1]>>a[2];
        sort(a.begin(),a.end());
        mp[{a[0],a[1]}]={a[2],i};

        if(a[0]>ans_r)
        {
            ans_r=a[0];
            ans_id={i};
        }

        vector<tuple<int,int,int>> faces =
        {
            {a[0],a[1],a[2]},
            {a[0],a[2],a[1]},
            {a[1],a[2],a[0]}
        };
        for(auto[x,y,z] : faces)
        {
            pair<int,int> base={x,y};
            if(mp.count({x,y}))
            {
                Stone pre=mp[base];
                int new_h=z+pre.height;
                int cur_r=min({x,y,new_h});

                if(cur_r>ans_r)
                {
                    ans_r=cur_r;
                    ans_id={pre.id,i};
                }
            }
        }

        for(auto[x,y,z] : faces)
        {
            pair<int,int> base={x,y};
            if(!mp.count(base)||z>mp[base].height) mp[base]={z,i};
        }
    }

    cout<<ans_id.size()<<endl;
    for(int id : ans_id) cout<<id<<" ";
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}