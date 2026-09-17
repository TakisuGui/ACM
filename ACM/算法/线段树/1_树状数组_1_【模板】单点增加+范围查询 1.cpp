#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=5e5+10;
const int base=499;
const int MOD=1e7+7;

vector<int> tree(N);
int n,m;

int lowbit(int x)
{
    return x&(-x);
}

void add(int i,int v)
{
    while(i<=n)
    {
        tree[i]+=v;
        i+=lowbit(i);
    }
}

int sum(int i) // 返回1~i范围累加和
{
    int ans=0;
    while(i>0)
    {
        ans+=tree[i];
        i-=lowbit(i);
    }
    return ans;
}

int range_sum(int l,int r)
{
    return sum(r)-sum(l-1);
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        add(i,x);
    }

    while(m--)
    {
        int op,x,k; cin>>op>>x>>k;
        
        if(op==1) add(x,k);
        else cout<<range_sum(x,k)<<endl;
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