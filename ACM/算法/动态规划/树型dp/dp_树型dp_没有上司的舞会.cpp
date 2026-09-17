#include<bits/stdc++.h>
using namespace std;

const int N=6e3+10;

int n;
vector<int> edges[N];
int a[N];
int dp[N][2];
bool has_father[N];

void dfs(int u)
{
    dp[u][1]=a[u];
    dp[u][0]=0;
    for(int v:edges[u])
    {
        dfs(v);
        dp[u][1]+=dp[v][0];
        dp[u][0]+=max(dp[v][0],dp[v][1]);
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n-1;i++)
    {
        int a,b; cin>>a>>b;
        edges[b].push_back(a);
        has_father[a]=true; 
    }

    //找根_没有上司的节点
    int root=1;
    for(int i=1;i<=n;i++)
    {
        if(!has_father[i])
        {
            root=i;
            break;
        }       
    }

    dfs(root);

    cout<<max(dp[root][0],dp[root][1])<<endl;

    return 0;
}

