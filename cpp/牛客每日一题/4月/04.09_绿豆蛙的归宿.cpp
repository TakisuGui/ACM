#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int  N=1e5+10;

vector<pair<int,double>> edges[N];
double dp[N];
queue<int> q;
int in[N];
int pre_out[N];

void solve()
{
    int n,m; cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,c; cin>>a>>b>>c;
        edges[b].push_back({a,c});
        in[a]++;
        pre_out[a]++;
    }

    dp[n]=0;
    q.push(n);

    while(!q.empty())
    {
        auto top=q.front(); q.pop();

        for(auto v:edges[top])
        {
            dp[v.first]+=(dp[top]+1.0*v.second)/pre_out[v.first];
            in[v.first]--;

            if(in[v.first]==0) q.push(v.first);
        }
    }

    printf("%.2lf",dp[1]);
}


int main()
{
    solve();
    
    return 0;
}