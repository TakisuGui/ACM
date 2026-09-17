#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
vector<int>edges[N];
bool win[N];

void dfs(int u,int fa)
{
    int win_child=0;
    bool leaf=true;

    for(auto v:edges[u])
    {
        if(v==fa) continue;

        leaf=false;
        dfs(v,u);

        if(win[v]) win_child++;
    }

    if(leaf) win[u]=true;
    else
    {
        if(win_child>=2) win[u]=true;
        else win[u]=false;
    }
}

void slove()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        edges[i].clear();
        win[i]=false;
    }

    for(int i=0;i<n-1;i++)
    {
        int u,v; cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    if(n==1)
    {
        cout<<"red"<<endl;
        return;
    }

    dfs(1,0);

    bool red_win=false;
    for(auto v:edges[1])
    {
        if(win[v])
        {
            red_win=true;
            break;
        }
    }

    if(red_win) cout<<"red"<<endl;
    else cout<<"purple"<<endl;


}

int main()
{
    int t; cin>>t;
    while (t--)
    {
        slove();
    }
    return 0;
}