#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=110;

int a[N];
vector<pair<int,int>> line;

void solve()
{
    int t,x; cin>>t>>x;
    for(int i=0;i<=t;i++) cin>>a[i];

    line.push_back({0,a[0]}); int v=a[0];

    for(int i=1;i<=t;i++)
    {
        if(abs(a[i]-v)>=x)
        {
            line.push_back({i,a[i]});
            v=a[i];
        }
    }

    for(auto p: line) cout<<p.first<<" "<<p.second<<endl;
    
}

int main()
{
    solve();

    return 0;
}