#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int MOD=1e4+7;

string x;
int n;
vector<int> edges[10];
bool vis[10];

void dfs(int u,set<int> &s)
{
    if(vis[u]) return;
    vis[u]=true;

    s.insert(u);
    for(auto v:edges[u]) dfs(v,s);
}

int main()
{
    cin>>x>>n;

    while(n--)
    {
        int a,b; cin>>a>>b;
        edges[a].push_back(b);
    }

    ll ans=1;
    for(char c:x)
    {
        int digit=c-'0';
        memset(vis,false,sizeof vis);
        set<int> s;
        dfs(digit,s);

        ans=(ans*s.size())%MOD;
    }

    cout<<ans<<endl;

    return 0;
}