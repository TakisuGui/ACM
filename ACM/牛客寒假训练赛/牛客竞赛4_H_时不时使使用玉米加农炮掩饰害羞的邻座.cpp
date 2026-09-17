#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;
const int MOD=998244353;
const int P=13331;

priority_queue<int,vector<int>,greater<int>> heap_small;//小跟堆
priority_queue<int,vector<int>,less<int>> heap_big;//大跟堆

ll qpow(ll a,ll b,ll c)//(a^b) mod c
{ 
    ll ans =1;
    a%=c;
    while(b)
    {
        if(b&1) ans=(ans*a) %c;
        a=a*a%c;
        b>>=1;
    }
    return ans;
}

ll gcd(ll a,ll b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

ll floor_log2(ll x)
{
    if(x<=1) return 0;
    else return 63-__builtin_clzll(x);
}

void untie()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const int MAX=510;

int dx[13]={0,1,2,-1,-2,-1,0,1,0,-1,0,1,0};
int dy[13]={0,0,0,0,0,1,1,1,2,-1,-1,-1,-2};

int n,m,q;
ll a[MAX][MAX];
ll cur_kill[MAX][MAX];

priority_queue<pair<ll,pair<int,int>>> pq;

bool in(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=m) return true;
    else return false;
}

void ini()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ll sum=0;
            for(int k=0;k<13;k++)
            {
                int nx=i+dx[k]; int ny=j+dy[k];

                if(in(nx,ny))
                {
                    sum+=a[nx][ny];
                }
            }

            cur_kill[i][j]=sum;
            pq.push({sum,{i,j}});
        }
    }
}

void add(int x,int y,ll z)
{
    for(int k=0;k<13;k++)
    {
        int nx=x+dx[k]; int ny=y+dy[k];
        if(in(nx,ny))
        {
            cur_kill[nx][ny]+=z;
            pq.push({cur_kill[nx][ny],{nx,ny}});
        }
    }
}

pair<int,int> reply()
{
    while(!pq.empty())
    {
        auto top=pq.top();
        ll tmp=top.first;
        int re_x=top.second.first;
        int re_y=top.second.second;

        if(tmp!=cur_kill[re_x][re_y])
        {
            pq.pop();
            continue;
        }

        return {re_x,re_y};
    }

    return {1,1};
}

int main()
{
    untie();

    cin>>n>>m>>q;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }

    ini();

    for(int i=1;i<=q;i++)
    {
        int x,y;ll z; cin>>x>>y>>z;

        add(x,y,z);

        cout<<reply().first<<" "<<reply().second<<endl;
    }

    return 0;
}