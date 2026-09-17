#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e6+10;
const int base=499;
const int MOD=1e7+7;

vector<int> tree(N);
vector<int> a(N);
vector<int> ans(N);
vector<int> mp(N);
vector<vector<int>> query(N,vector<int>(3));
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
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>query[i][0]>>query[i][1];
        query[i][2]=i;
    }

    sort(query.begin()+1,query.begin()+m+1,[](const vector<int>& a,const vector<int>& b)
    {
        return a[1]<b[1];
    });

    for(int j=1,s=1,l,r,i;j<=m;j++)
    {
        r=query[j][1];
        for(;s<=r;s++)
        {
            int color=a[s];
            if(mp[color]!=0)
            {
                add(mp[color],-1);
            }
            add(s,1);
            mp[color]=s;
        }
        l=query[j][0],i=query[j][2];
        ans[i]=range_sum(l,r);
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
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