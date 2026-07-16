#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;

vector<int> edges[N];
vector<string> s;
vector<vector<bool>>vis,inStack;
bool found;
int n,m,w;

void dfs(int u,int day)
{
    if(found) return;
    if(inStack[u][day]) {found=true; return;}

    if(vis[u][day]) return;

    vis[u][day]=true;
    inStack[u][day]=true;

    int next=(day%w)+1;
    if(s[u][next]=='o') dfs(u,next);

    for(auto v:edges[u])
    {
        if(s[v][next]=='o') dfs(v,next);
    }

    inStack[u][day]=false;
}

void solve()
{
    cin>>n>>m;
    for(int i=1; i<=n;i++) edges[i].clear();
    for(int i=0;i<m;i++)
    {
        int u,v; cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    cin>>w;
    s.resize(n+1,"");
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        s[i]=' '+s[i];
    }

    vis.assign(n+1,vector<bool>(w+1,false));
    inStack.assign(n+1,vector<bool>(w+1,false));
    found=false;

    for(int i=1;i<=n&&!found;i++) if(s[i][1]=='o') dfs(i,1);

    cout<<(found ? "Yes" : "No")<<endl;
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