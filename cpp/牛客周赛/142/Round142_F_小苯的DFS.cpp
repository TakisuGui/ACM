#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=2e5+10;
const int MOD=998244353;

ll f[N+10];
ll inv_f[N+10];
int a[N];

ll qpow(ll a,ll b,ll c)
{ 
    ll ans=1;
    a%=c;
    while(b)
    {
        if(b&1) ans=(ans*a)%c;
        a=a*a%c;
        b>>=1;
    }
    return ans;
}
void init()
{
    f[0]=1;
    for(int i=1;i<=N;i++)
    {
        f[i]=f[i-1]*i%MOD;
    }

    //求逆元
    inv_f[N]=qpow(f[N],MOD-2,MOD)%MOD;
    for(int i=N-1;i>=0;i--)
    {
        inv_f[i]=inv_f[i+1]*(i+1)%MOD;
    }
}


void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<vector<int>> edges(n+1);

    for(int i=0;i<n-1;i++)
    {
        int u,v; cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> mn(n+1),mx(n+1);
    vector<int> p(n+1);

    auto dfs=[&](auto self,int u,int fa)->void
    {
        mn[u]=a[u],mx[u]=a[u];
        p[u]=1;

        vector<pair<int,int>> son;
        int k=0; //儿子数量

        for(auto v:edges[u])
        {
            if(v==fa) continue;
            self(self,v,u);
            k++;

            if(p[v]==0) p[u]=0;
            son.push_back({mn[v],mx[v]});
            if(p[u]!=0) p[u]=p[u]*p[v]%MOD;
        }

        if(k==0||p[u]==0) return;

        sort(son.begin(),son.end());
        if(a[u]>son[0].first)
        {
            p[u]=0;
            return;
        }
        for(int i=0;i<k-1;i++)
        {
            if(son[i].second>son[i+1].first)
            {
                p[u]=0;
                return;
            }
        }

        int ways=1;
        int cnt=1;
        for(int i=1;i<k;i++)
        {
            if(son[i]==son[i-1])
            {
                cnt++;
                ways=ways*cnt%MOD;
            }
            else cnt=1;
        }

        p[u]=p[u]*ways%MOD*inv_f[k]%MOD;
        mx[u]=son.back().second;  
    };

    dfs(dfs,1,0);

    cout<<p[1]<<endl;
}

signed main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}