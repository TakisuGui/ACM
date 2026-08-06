#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=5e5+10;

vector<int> tree1(N);
vector<int> tree2(N);
int n,m;

int lowbit(int x)
{
    return x&(-x);
}

void add(vector<int>& tree,int i,int k)
{
    while(i<=n)
    {
        tree[i]+=k;
        i+=lowbit(i);
    }
}

int sum(vector<int>& tree,int i)
{
    int ans=0;
    while(i>0)
    {
        ans+=tree[i];
        i-=lowbit(i);
    }
    return ans;
}

void add(int l,int r,int v)
{
    add(tree1,l,v);
    add(tree1,r+1,-v);
    add(tree2,l,(l-1)*v);
    add(tree2,r+1,-(r*v));
}

int range_sum(int l,int r)
{
    return sum(tree1,r)*r-sum(tree2,r)-sum(tree1,l-1)*(l-1)+sum(tree2,l-1);
}

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        add(i,i,x);
    }

    while(m--)
    {
        int op; cin>>op;
        if(op==1)
        {
            int x,y,k; cin>>x>>y>>k;
            add(x,y,k);
        }
        else
        {
            int x,y; cin>>x>>y;
            cout<<range_sum(x,y)<<endl;
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