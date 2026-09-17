#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;

void solve()
{   
    int n; cin>>n;
    vector<pair<int,int>> p(n);
    unordered_map<int,vector<int>> mpx,mpy;

    for(int i=0;i<n;i++)
    {
        cin>>p[i].first>>p[i].second;
        mpx[p[i].first].push_back(p[i].second);
        mpy[p[i].second].push_back(p[i].first);
    }

    int ans=0;

    for(auto& [y,x_list] : mpy)
    {
        int m=x_list.size();
        if(m<2) continue;

        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                ll sum=x_list[i]+x_list[j];
                if(sum%2==0)
                {
                    int mid=sum/2;
                    if(mpx.count(mid))
                    {
                        for(int k:mpx[mid]) if(k!=y) ans++;
                    }
                }
            }
        }
    }
    for(auto& [x,y_list] : mpx)
    {
        int m=y_list.size();
        if(m<2) continue;

        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                ll sum=y_list[i]+y_list[j];
                if(sum%2==0)
                {
                    int mid=sum/2;
                    if(mpy.count(mid))
                    {
                        for(int k:mpy[mid]) if(k!=x) ans++;
                    }
                }
            }
        }
    }

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