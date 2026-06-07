#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6;


void solve()
{
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int ans=0;
    sort(a.begin(),a.end());

    deque<int> q1;
    for(int i=0;i<n;i++) q1.push_back(a[i]);
    vector<int> q2;
    int pass=1;
    while(!q1.empty())
    {
        if(pass==1)
        {
            q2.push_back(q1.front());
            q1.pop_front();
            pass=0;
        }
        else
        {
            q2.push_back(q1.back());
            q1.pop_back();
            pass=1;
        }
    }

    ans+=abs(q2[0]-q2[q2.size()-1]);
    for(int i=1;i<q2.size();i++) ans+=abs(q2[i]-q2[i-1]);

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