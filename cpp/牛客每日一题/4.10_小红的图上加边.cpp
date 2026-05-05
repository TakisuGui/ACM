#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int  N=1e5+10;

vector<int> edges[N];
ll a[N];
bool visited[N];
ll max_dex[N];

void solve()
{
    int n,m; cin>>n>>m;

    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int v, u; cin>>u>>v;
        edges[v].push_back(u);
        edges[u].push_back(v);
    }

    int j=0;

    for(int i=1;i<=n;i++)
    {
        queue<int> q;
        if(!visited[i])
        {
            j++;
            q.push(i);
            visited[i]=true;
            max_dex[j]=max(max_dex[j],a[i]);
            while(!q.empty())
            {
                auto top=q.front(); q.pop();
                for(auto v:edges[top])
                {
                    if(!visited[v])
                    {
                        visited[v]=true;
                        max_dex[j]=max(max_dex[j],a[v]);
                        q.push(v);
                    }
                }
            }
            
        }
    }

    sort(max_dex+1,max_dex+j+1);
    ll ans=0;
    for(int i=2;i<=j;i++) ans+=max_dex[i];
    
    cout<<ans<<endl;
}


int main()
{
    solve();

    return 0;
}