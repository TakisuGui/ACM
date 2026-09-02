#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{
    int n; cin>>n;
    vector<pair<int,int>> point(n+1);
    for(int i=1;i<=n;i++) cin>>point[i].first>>point[i].second;

    map<pair<int,int>,vector<pair<int,int>>> mp;

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int mid_x=point[i].first+point[j].first;
            int mid_y=point[i].second+point[j].second;
            mp[{mid_x,mid_y}].push_back({i,j});
        }
    }

    int mx=-1;

    for(auto& [center,lines] : mp)
    {
        int sz=lines.size();
        if(sz<2) continue;

        for(int i=0;i<sz;i++)
        {
            for(int j=i+1;j<sz;j++)
            {
                int p1=lines[i].first,p2=lines[i].second;
                int p3=lines[j].first,p4=lines[j].second;

                int x1=point[p1].first,y1=point[p1].second;
                int x2=point[p2].first,y2=point[p2].second;
                int x3=point[p3].first,y3=point[p3].second;

                int dex1x=x2-x1,dex1y=y2-y1;
                int dex2x=x3-x1,dex2y=y3-y1;

                int area=abs(dex1x*dex2y-dex2x*dex1y);
                mx=max(mx,area);
            }
        }
    }

    if(mx<=0){cout<<-1<<endl; return;}
    else cout<<mx<<".0"<<endl;
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