#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=5e5+10;

vector<int> tree(N);
int n,m;

int lowbit(int x)
{
    return x&(-x);
}

void add(int i,int k)
{
    while(i<=n)
    {
        tree[i]+=k;
        i+=lowbit(i);
    }
}

int sum(int i)
{
    int ans=0;
    while(i>0)
    {
        ans+=tree[i];
        i-=lowbit(i);
    }
    return ans;
}

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        add(i,x); add(i+1,-x);
    }

    while(m--)
    {
        int op; cin>>op;
        if(op==1)
        {
            int x,y,k; cin>>x>>y>>k;
            add(x,k); add(y+1,-k);
        }
        else
        {
            int x; cin>>x;
            cout<<sum(x)<<endl;
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