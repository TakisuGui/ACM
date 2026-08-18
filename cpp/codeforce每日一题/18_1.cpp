#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=2e5;
const int MOD=1e9+7;

void solve()
{
    int x,y,n; cin>>x>>y>>n;

    pair<int,int> ans={-1,-1};
    int cur=1e18;

    for(int b=1;b<=n;b++)
    {
        int goal=b*x;
        int l=0,r=1e10+10,ans1=r+1;

        while(l<=r)
        {
            int mid=(l+r)>>1;

            if(goal<=mid*y)
            {
                ans1=mid;
                r=mid-1;
            }
            else l=mid+1;
        }

        l=0,r=1e10+10; int ans2=-1;
        while(l<=r)
        {
            int mid=(l+r)>>1;

            if(goal>mid*y)
            {
                ans2=mid;
                l=mid+1;
            }
            else r=mid-1;
        }

        int can[2]={ans1,ans2};
        for(auto& a : can)
        {
            if(ans.first==-1) {ans={a,b}; continue;}

            int cur=abs(b*x-a*y)*ans.second;
            int best=abs(ans.second*x-ans.first*y)*b;

            if(cur<best) ans={a,b};
            else if(cur==best)
            {
                if(b<ans.second) ans={a,b};
                else if(b==ans.second&&a<ans.first) ans={a,b};
            }
        }
    }

    cout<<ans.first<<"/"<<ans.second<<endl;
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