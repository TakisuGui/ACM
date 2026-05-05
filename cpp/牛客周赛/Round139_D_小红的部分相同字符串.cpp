#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
vector<int> edges[N];
const int MOD=998244353;
bool visited[N];

int main()
{
    int n,k; cin>>n>>k;

    for(int i=1;i<=k;i++)
    {
        int u,v; cin>>u>>v;
        edges[v].push_back(u);
        edges[u].push_back(v);
    }

    int group=n;

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            queue<int> q;
            q.push(i);
            visited[i]=true;

            while(!q.empty())
            {
                auto top=q.front(); q.pop();
                for(auto v:edges[top])
                {
                    if(!visited[v])
                    {
                        visited[v]=true;
                        q.push(v); group--;
                    }
                }
            }
        }
    }

    ll ans=1;
    for(int i=1;i<=group;i++) ans*=26,ans%=MOD;

    cout<<ans%MOD<<endl;

    return 0;
}