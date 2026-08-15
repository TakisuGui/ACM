#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=2e6+10;
const int base=499;
const int MOD=1e7+7;

vector<int> tree(N);
vector<int> a(N);
vector<int> ans(N);
vector<int> first_pos(N);
vector<int> second_pos(N);
vector<vector<int>> query(N,vector<int>(3));
int n,m,c;

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

int range_sum(int l,int r)
{
    return sum(r)-sum(l-1);
}

void solve()
{
    cin>>n>>c>>m;
    for(int i=1;i<=n;i++) cin>>a[i];

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
        l=query[j][0],r=query[j][1],i=query[j][2];

        for(;s<=r;s++)
        {
            int color=a[s];
            if(first_pos[color]==0) first_pos[color]=s;
            else if(second_pos[color]==0&&first_pos[color]!=0)
            {
                second_pos[color]=first_pos[color];
                add(second_pos[color],1);
                first_pos[color]=s;
            }
            else
            {
                add(second_pos[color],-1);
                second_pos[color]=first_pos[color];
                add(second_pos[color],1);
                first_pos[color]=s;
            }
        }
        ans[i]=range_sum(l,r);
    }

    for(int i=1;i<=m;i++)  cout<<ans[i]<<endl;
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