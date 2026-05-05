#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
vector<int> edges[N];

void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) edges[i].clear();
    for(int i=1;i<n;i++)
    {
        int v,u; cin>>v>>u;
        edges[v].push_back(u);
        edges[u].push_back(v);
    }

    vector<int> st, fa(n+1),siz(n+1),order;
    st.push_back(1);
    fa[1]=0;

    while(!st.empty())
    {
        int u=st.back(); st.pop_back();
        order.push_back(u);
        for(auto v:edges[u])
        {
            if(v==fa[u]) continue;
            fa[v]=u;
            st.push_back(v);
        }
    }

    vector<vector<int>> dp(n+1,vector<int>(2));

    for(int i=n-1;i>=0;i--) //保证子节点先于父节点被处理
    {
        int u=order[i];
        siz[u]=1;
        dp[u][0]=0;  //不选u
        dp[u][1]=1;  //选u

        for(auto v:edges[u])
        {
            if(v==fa[u]) continue;
            siz[u]+=siz[v];
            dp[u][0]+=max(dp[v][0],dp[v][1]);
            dp[u][1]+=dp[v][0];
        }
    }

    for(int i=1;i<=n;i++)cout<<siz[i]-max(dp[i][0],dp[i][1])<<" ";
    cout<<endl;
}

int main()
{
    int t; cin>>t;
    while(t--) solve();

    return 0;
}