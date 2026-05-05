#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int pts[21][6]=
{
    {9,0,0,0,0,0},{1,4,0,0,0,0},{3,3,0,0,0,0},{5,2,0,0,0,0},{7,1,0,0,0,0},
    {0,0,3,0,0,0},{1,1,2,0,0,0},{3,0,2,0,0,0},{0,3,1,0,0,0},{2,2,1,0,0,0},
    {4,1,1,0,0,0},{6,0,1,0,0,0},{0,1,1,1,0,0},{2,0,1,1,0,0},{1,2,0,1,0,0},
    {3,1,0,1,0,0},{5,0,0,1,0,0},{0,0,1,0,1,0},{1,1,0,0,1,0},{3,0,0,0,1,0},
    {0,0,0,0,0,1}
};

void solve()
{
    int n; cin>>n;
    vector<ll> items[6];
    for(int i=0;i<n;i++)
    {
        int a,b; ll v; cin>>a>>b>>v;
        if(a>b) swap(a,b);
        int t;
        if(a==1) t=b-1;      //1x1->0,1x2->1,1x3->2
        else if(a==2) t=b+1; //2x2->3,2x3->4
        else if(a==3) t=5;   //3x3->5
        items[t].push_back(v);
    }

    for(int i=0;i<6;i++) sort(items[i].rbegin(),items[i].rend());//降序

    ll max_ans=0;
    for(int p_idx=0;p_idx<21;p_idx++)
    {
        ll cur_v=0;
        for(int i=0;i<6;i++)
        {
            int take=min((int)items[i].size(),pts[p_idx][i]);
            for(int k=0;k<take;k++) cur_v+=items[i][k];
        }

        max_ans=max(max_ans,cur_v);
    }

    cout<<max_ans<<endl;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}