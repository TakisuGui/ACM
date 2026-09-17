#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=3e5+10;
const int MOD=1e9+7;

vector<int> a(N),b(N);
vector<int> dis(N,-1); // 记录到达深度 i 的最少跳跃次数
vector<int> jumpfrom(N); // 到达深度 i 是从哪个深度跳过来的
vector<int> jumpto(N); // 达深度 i 时，下滑前的那个深度是多少


void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    queue<int> q;
    int max_reach=n;
    q.push(n);
    dis[n]=0;

    while(!q.empty())
    {
        auto u=q.front(); q.pop();
        if(u==0) break;

        int top=u-a[u];
        
        if(top<max_reach)
        {
            for(int v=top;v<max_reach;v++)
            {
                if(v<0) break;

                int next_pos=v+b[v];

                if(dis[next_pos]==-1)
                {
                    dis[next_pos]=dis[u]+1;
                    jumpfrom[next_pos]=u;
                    jumpto[next_pos]=v;
                    q.push(next_pos);
                }
            }
        }

        max_reach=min(max_reach,top);
    }

    if(dis[0]==-1)
    {
        cout<<-1<<endl;
        return;
    }
    cout<<dis[0]<<endl;

    vector<int> path;
    int cur=0;
    while(cur!=n)
    {
        path.push_back(jumpto[cur]);
        cur=jumpfrom[cur];
    }
    reverse(path.begin(),path.end());

    for(int i=0;i<path.size();i++) cout<<path[i]<<" ";
    cout<<endl;
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