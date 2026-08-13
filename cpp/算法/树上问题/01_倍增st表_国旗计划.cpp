#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=2e5+10;
const int MOD=1e7+7;
const int LIMIT=18;

vector<vector<int>> line(N<<1,vector<int>(3));
// stjump[i][p] : 从i号线段出发，跳的次数是2的p次方，能到达的最右线段的编号
vector<vector<int>> st(N<<1,vector<int>(LIMIT));
vector<int> ans(N);
int n,m; 
int power;

int log2(int i)
{
    int ans=0;
    while((1<<ans)<=(i>>1)) ans++;
    return ans;
}

void build()
{
    for(int i=1;i<=n;i++)
    {
        if(line[i][1]>line[i][2]) line[i][2]+=m;
    }

    sort(line.begin()+1,line.begin()+n+1,[](const vector<int>&a,const vector<int>&b)
    {
        return a[1]<b[1];
    });

    for(int i=1;i<=n;i++)
    {
        line[i+n][0]=line[i][0];
        line[i+n][1]=line[i][1]+m;
        line[i+n][2]=line[i][2]+m;
    }
    int e=n<<1;

    for(int i=1,arrive=1;i<=e;i++)
    {
        while(arrive+1<=e&&line[arrive+1][1]<=line[i][2]) arrive++;

        st[i][0]=arrive;
    }
    

    for(int p=1;p<=power;p++)
    {
        for(int i=1;i<=e;i++)
        {
            st[i][p]=st[st[i][p-1]][p-1];
        }
    }
}

int jump_(int i)
{
    int aim=line[i][1]+m,cur=i,next_,ans=1;

    for(int p=power;p>=0;p--)
    {
        next_=st[cur][p];
        if(next_!=0&&line[next_][2]<aim)
        {
            ans+=1<<p;
            cur=next_;
        }
    }
    return ans+1;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        line[i][0]=i;
        cin>>line[i][1]>>line[i][2];
    }
    power=log2(n);

    build();

    for(int i=1;i<=n;i++)
    {
        ans[line[i][0]]=jump_(i);
    }

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
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