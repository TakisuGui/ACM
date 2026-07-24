#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e9+7;

struct Point
{
    int x; int y;
};

void solve()
{
    int n; cin>>n;
    vector<Point> points(n+1);
    for(int i=1;i<=n;i++){ cin>>points[i].x>>points[i].y;}

    for(int i=2;i<=n-1;i++)
    {
        int x1=points[i].x-points[i-1].x;
        int y1=points[i].y-points[i-1].y;
        int x2=points[i+1].x-points[i].x;
        int y2=points[i+1].y-points[i].y;

        int t=x1*y2-x2*y1;
        if(t>0) cout<<"LEFT"<<" ";
        else if(t==0) cout<<"STRAIGHT"<<" ";
        else cout<<"RIGHT"<<" ";
    }
    cout<<endl;
}


signed main()
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
