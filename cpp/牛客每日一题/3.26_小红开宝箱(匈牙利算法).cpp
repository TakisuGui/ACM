#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;
vector<int>edges[N];
bool vis[N];
int match[N];
int ans[N];

bool dfs(int x)
{
    for(auto i:edges[x])
    {
        if(vis[i]) continue;
        vis[i]=true;
        if(match[i]==0||dfs(match[i]))
        {
            match[i]=x;
            return true;
        }
    }

    return false;
}

void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        int t; cin>>t;
        for(int j=1;j<=t;j++)
        {
            int x; cin>>x;
            edges[i].push_back(x);
        }
    }

    for(int i=1;i<=n;i++)
    {
        memset(vis,false,sizeof vis);
        if(dfs(i)==false)
        {
            cout<<"kou is angry"<<endl;
            return;
        }
    }

    for(int i=1;i<=n;i++) ans[match[i]]=i;
    for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
    cout<<endl;
}

int main()
{
    solve();
    
    return 0;
}
