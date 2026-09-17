#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e9+7;

struct tree
{
    int h,c;
};

void solve()
{
    int n,m; cin>>n>>m;
    vector<tree>  t(n);
    int max_h=-1;
    for(int i=0;i<n;i++)
    {
        cin>>t[i].h>>t[i].c;
        max_h=max(max_h,t[i].h);
    }

    int l=1,r=2*max_h,ans=r+1;

    while(l<=r)
    {
        int mid=l+(r-l)/2;
        int total_len=0;

        for(int i=0;i<n;i++)
        {
            int min_h=max(t[i].c,mid/2);  // 至少保留的高度
            if(t[i].h>min_h) total_len+=(t[i].h-min_h);
        }

        if(total_len<=m)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }

    ll total=0,used=0;

    for(int i=0;i<n;i++)
    {
        int min_h=max(t[i].c,ans/2);
        if(t[i].h>min_h) 
        {
            int cnt=t[i].h-min_h;
            used+=cnt;

            int first=2*t[i].h-1;
            int last=2*(min_h+1)-1;
            total+=cnt*(first+last)/2;
        }
    }

    int rem=m-used;
    if(rem>0&&ans>1) total+=rem*(ans-1);

    cout<<total<<endl;
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
