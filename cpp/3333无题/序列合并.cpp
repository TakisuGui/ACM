#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e7+7;

vector<int> a(N);
vector<int> b(N);

int dx[]={1,0};
int dy[]={0,1};

bitset<N> vis[N];

void solve()
{
   int n; cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i];
   for(int i=1;i<=n;i++) cin>>b[i];


   sort(a.begin()+1,a.begin()+1+n);
   sort(b.begin()+1,b.begin()+1+n);

   priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;

   vector<int> ans;
   q.push({a[1]+b[1],{1,1}});
   vis[1][1]=true;

    while((int)ans.size()<n)
    {
        auto [v,p] = q.top(); q.pop();
        int x=p.first,y=p.second;
        ans.push_back(v);
        
        if(x+1<=n&&!vis[x+1][y]) q.push({a[x+1]+b[y],{x+1,y}}),vis[x+1][y]=true;
        if(y+1<=n&&!vis[x][y+1]) q.push({a[x]+b[y+1],{x,y+1}}),vis[x][y+1]=true;
        
    }

    for(auto& v : ans) cout<<v<<" ";
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