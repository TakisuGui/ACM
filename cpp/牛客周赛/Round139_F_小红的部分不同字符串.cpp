#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mod=998244353;

vector<int> a(N+1,0),in(N+1,0),del(N+1,0),vis(N+1,0);

ll qpow(ll a,ll b, ll c)
{
    ll ans=1; a%=c;
    while(b)
    {
        if(b&1) ans=(ans*a)%c;
        a=a*a%c;
        b>>=1;
    }

    return ans;
}

void solve()
{
    int n; cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        in[a[i]]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0) q.push(i);
    }
    
    int cnt=0; //非环点个数

    while(!q.empty())
    {
        auto u=q.front(); q.pop();
        del[u]=1; //标记不在环上
        cnt++;
        int v=a[u];
        in[v]--;
        if(in[v]==0) q.push(v);
    }

    ll ans=qpow(25,cnt,mod)%mod;

    for(int i=1;i<=n;i++)
    {
        if(del[i]||vis[i]) continue;

        int len=0;     //环的长度
        int u=i;       //从当前起点 i 开始走
        while(!vis[u]) 
        {
            vis[u]=1;
            len++;
            u=a[u];    //沿着出边走到下一个节点
        }

        int have=qpow(25,len,mod);
        if(len%2==0) ans=ans*((have+25)%mod)%mod;
        else ans=ans*((have-25+mod)%mod)%mod;
    }

    cout<<ans%mod<<endl;
}


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}