#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const int LIM=20;
#define endl "\n"

int power;
vector<int> edges[N];
int st[N][LIM];
int deep[N];
int n;

int log2(int n)
{
    int ans=0;
    while((1<<ans)<=(n>>1)) ans++;
    return ans;
}

void dfs(int u,int f)
{
    if(u==1) deep[u]=1;
    else deep[u]=deep[f]+1;

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
    cin>>n;
    power=log2(n);
    for(int i=1;i<n;i++)
    {
        int u,v; cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1,0);

    int m; cin>>m;
    while(m--)
    {
        int k; cin>>k;
        vector<int> a(k); int max_deep=0; int max_deep_id=-1;
        for(int i=0;i<k;i++) 
        {
            cin>>a[i];
            if(max_deep<deep[a[i]]) {max_deep=deep[a[i]],max_deep_id=a[i];}
        }

        vector<int> other;
        for(int i=0;i<k;i++)
        {
            if(a[i]==max_deep_id) continue;
            if(lca(max_deep_id,a[i])!=a[i]) other.push_back(a[i]);
        }

        if(other.empty())
        {
            cout<<"YES"<<endl;
            continue;
        }
        int second_max_deep=0; int second_max_deep_id=-1;
        for(auto& x : other)
        {
            if(second_max_deep<deep[x]) {second_max_deep=deep[x],second_max_deep_id=x;}
        }
        int toge=lca(max_deep_id,second_max_deep_id);

        bool pass=true;
        for(int i=0;i<k;i++)
        {
            if(a[i]==max_deep_id||a[i]==second_max_deep_id) continue;
            

            bool p1=(lca(a[i],max_deep_id)==a[i])&&(lca(toge,a[i])==toge);
            bool p2=(lca(a[i],second_max_deep_id)==a[i])&&(lca(toge,a[i])==toge);

            if(!(p1|p2))
            {
                pass=false;
                break;
            }
        }

        cout<<(pass ? "YES" : "NO")<<endl;
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