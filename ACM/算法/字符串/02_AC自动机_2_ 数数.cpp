#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int MOD=1e9+7;
const int M=1310;
const int N=2e3;

int n;
string num;
vector<vector<int>> tree(N,vector<int>(10));
vector<int> fail(N);
int cnt=0;
vector<bool> alert(N);
int dp[M][N][2][2];

void insert_(int i,string t) // 每一个字符分配节点
{
    int u=0;
    for(int j=0;j<t.size();j++)
    {
        int c=t[j]-'0';
        if(tree[u][c]==0) tree[u][c]=++cnt;

        u=tree[u][c];
    }
    alert[u]=true;
}

void setfail()
{
    queue<int> q;
    for(int i=0;i<=9;i++)
    {
        if(tree[0][i]!=0) q.push(tree[0][i]);
    }

    while(!q.empty())
    {
        int u=q.front(); q.pop();
        for(int i=0;i<=9;i++)
        {
            if(tree[u][i]==0) tree[u][i]=tree[fail[u]][i];
            else 
            {
                fail[tree[u][i]]=tree[fail[u]][i];
                q.push(tree[u][i]);
            }
        }

        alert[u]=(alert[u]|alert[fail[u]]);
    }
}

int f(int i,int j,int free,int has)
{
    if(alert[j]) return 0;
    if(i==n) return has;
    if(dp[i][j][free][has]!=-1) return dp[i][j][free][has];

    int ans=0;
    int cur=num[i]-'0';
    if(has==0)
    {
        if(free==0)
        {
            ans=(ans+f(i+1,0,1,0))%MOD;

            for(int pick=1;pick<cur;pick++) ans=(ans+f(i+1,tree[j][pick],1,1))%MOD;

            ans=(ans+f(i+1,tree[j][cur],0,1))%MOD;
        }
        else
        {
            ans=(ans+f(i+1,0,1,0))%MOD;

            for(int pick=1;pick<=9;pick++) ans=(ans+f(i+1,tree[j][pick],1,1))%MOD;
        }
    }
    else
    {
        if(free==0)
        {
           for(int pick=0;pick<cur;pick++) ans=(ans+f(i+1,tree[j][pick],1,1))%MOD;

           ans=(ans+f(i+1,tree[j][cur],0,1))%MOD;
        }
        else
        {
            for(int pick=0;pick<=9;pick++) ans=(ans+f(i+1,tree[j][pick],1,1))%MOD;
        }
    }
    dp[i][j][free][has]=ans;
    return ans;
}

signed main()
{
    cin>>num; n=num.size();
    int m; cin>>m;
    for(int i=1;i<=m;i++)
    {
        string t; cin>>t;
        insert_(i,t);
    }
    setfail();
    memset(dp,-1,sizeof(dp));

    cout<<f(0,0,0,0)<<endl;
}

