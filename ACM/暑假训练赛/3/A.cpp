#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 500001;
const int LIM=19;
#define endl "\n"

int power;
vector<int> edges[N];
int st[N][LIM];
int deep[N];
int n,m;

int log2_(int n)
{
    int ans=0;
    while((1<<ans)<=(n>>1)) ans++;
    return ans;
}

void dfs(int u,int f)
{
    deep[u]=deep[f]+1;
    st[u][0]=f;

    for(int p=1;p<=power;p++)
    {
        st[u][p]=st[st[u][p-1]][p-1];
    }

    for(auto& v : edges[u])
    {
        if(v==f) continue;
        dfs(v,u);
    }
}

int lca(int a,int b)
{
    if(deep[a]<deep[b]) swap(a,b);

    for(int p=power;p>=0;p--)
    {
        if(deep[st[a][p]]>=deep[b]) a=st[a][p];
    }

    if(a==b) return a;

    for(int p=power;p>=0;p--)
    {
        if(st[a][p]!=st[b][p])
        {
            a=st[a][p];
            b=st[b][p];
        }
    }
    return st[a][0];
}

void solve()
{
    cin>>n>>m;
    power=log2_(n);
    for(int i=1;i<n;i++)
    {
        int a,b; cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1,0);

    int togather;
    int cost;

    while(m--)
    {
        int a,b,c; cin>>a>>b>>c;
        int h1=lca(a,b),h2=lca(a,c),h3=lca(b,c);
        int high = h1 != h2 ? (deep[h1] < deep[h2] ? h1 : h2) : h1;
		int low = h1 != h2 ? (deep[h1] > deep[h2] ? h1 : h2) : h3;
		togather = low;
		cost = (long) deep[a] + deep[b] + deep[c] - deep[high] * 2 - deep[low];

        cout<<togather<<" "<<cost<<endl;
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}