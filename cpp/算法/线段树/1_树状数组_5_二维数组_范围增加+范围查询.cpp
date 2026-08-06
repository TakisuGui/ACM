#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=2050;

int n,m;
vector<vector<int>> tree1(N,vector<int>(N));
vector<vector<int>> tree2(N,vector<int>(N));
vector<vector<int>> tree3(N,vector<int>(N));
vector<vector<int>> tree4(N,vector<int>(N));


int lowbit(int x)
{
    return x&(-x);
}

void add(int x,int y,int v)
{
    int v1=v;
    int v2=v*x;
    int v3=v*y;
    int v4=v*x*y;
    for(int i=x;i<=n;i+=lowbit(i))
    {
        for(int j=y;j<=m;j+=lowbit(j))
        {
            tree1[i][j]+=v1;
            tree2[i][j]+=v2;
            tree3[i][j]+=v3;
            tree4[i][j]+=v4;
        }
    }
}

int sum(int x,int y)
{
    int ans=0;
    for(int i=x;i>=1;i-=lowbit(i))
    {
        for(int j=y;j>=1;j-=lowbit(j))
        {
            ans+=(x+1)*(y+1)*tree1[i][j]-(y+1)*tree2[i][j]-(x+1)*tree3[i][j]+tree4[i][j];
        }
    }
    return ans;
}

void add(int a,int b,int c,int d,int v)
{
    add(a,b,v);
    add(a,d+1,-v);
    add(c+1,b,-v);
    add(c+1,d+1,v);
}

int range_sum(int a,int b,int c,int d)
{
   return sum(c,d)-sum(a-1,d)-sum(c,b-1)+sum(a-1,b-1);
}

void solve()
{
    char c; 

    while(cin>>c)
    {
        if(c=='X') cin>>n>>m;
        else if(c=='L')
        {
            int a,b,c,d,v; cin>>a>>b>>c>>d>>v;
            add(a,b,c,d,v);
        }
        else if(c=='k')
        {
            int a,b,c,d; cin>>a>>b>>c>>d;
            cout<<range_sum(a,b,c,d)<<endl;
        }
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