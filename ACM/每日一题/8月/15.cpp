#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
const int N=2e5;
const int MOD=1e7+7;

int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};


void solve()
{
    int n; cin>>n;
    map<pair<int,int>,int> mp;
    while(n--)
    {
        int x,y; cin>>x>>y;
        for(int i=0;i<8;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<1||nx>N||ny<1||ny>N) continue;

            mp[{nx,ny}]++;
        }
    }

    int max_=-1; pair<int,int> point;
    for(auto& [key,v] : mp) 
    {
        if(v>max_)
        {
            max_=v;
            point=key;
        }
    }

    cout<<point.first<<" "<<point.second<<endl;
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