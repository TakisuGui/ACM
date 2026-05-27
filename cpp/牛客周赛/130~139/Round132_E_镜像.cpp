#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=3e6+10;
const int MOD=998244353;
const int P=13331;
const int INF=0x3f3f3f3f;

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

int gcd(int a,int b)
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

int count_1(ll x)
{
    return __builtin_popcountll(x);
}

ll rev(ll x)
{
    ll res=0;
    while(x)
    {
        res=res*10+(x%10);
        x/=10;
    }

    return res;
}

int dis[N];

int solve(int a,int b,int k)
{
    if(a==b) return 0;
    queue<int> q;
    int max_val=2000000+k;
    memset(dis,-1,sizeof(dis)); 

    dis[a]=0; q.push(a);

    while(!q.empty())
    {
        int cur=q.front(); q.pop();

        if(cur%10!=0)
        {
            int rev_cur=rev(cur);
            if(rev_cur<max_val&&dis[rev_cur]==-1)
            {
                dis[rev_cur]=dis[cur]+1;
                if(rev_cur==b) return dis[rev_cur];
                q.push(rev_cur);
            }
        }

        int add=cur+k;
        if(add<max_val&&dis[add]==-1)
        {
            dis[add]=dis[cur]+1;
            if(add==b) return dis[add];
            q.push(add);
        }
    }
    return -1;
}

int main()
{
    untie();

    int t;cin>>t;
    while(t--)
    {
        int a,b,k; cin>>a>>b>>k;
        cout<<solve(a,b,k)<<endl;
    }

    return 0;
}