#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define int ll
const int N=1e5+10;

vector<int> a(N);
vector<int> edges[N];
int n,m;

bool check(int v)
{
    vector<int> group(n+3);
    vector<int> cnt0; vector<int> cnt1;
    vector<bool> vis(n+1,false);
    int comp0=0,comp1=0;

    for(int i=1;i<=n;i++)
    {
        if(a[i]<=v) group[i]=0,cnt0.push_back(i);
        else group[i]=1,cnt1.push_back(i);
    }
    if(cnt0.empty()||cnt1.empty()) return false;

    for(auto i : cnt0)
    {
        if(vis[i]) continue; vis[i]=true;
        queue<int> q; q.push(i);
        comp0++;

        while(!q.empty())
        {
            int first=q.front(); q.pop();
            for(auto j : edges[first])
            {
                if(group[j]==0&&!vis[j])
                {
                    vis[j]=true;
                    q.push(j);
                }
            }
        }
    }

    for(int i : cnt1)
    {
        if(vis[i]) continue; vis[i]=true;
        queue<int> q; q.push(i);
        comp1++;

        while(!q.empty())
        {
            int first=q.front(); q.pop();
            for(auto j : edges[first])
            {
                if(group[j]==1&&!vis[j])
                {
                    vis[j]=true;
                    q.push(j);
                }
            }
        }
    } 

    int total_components=comp0+comp1;
    int needed_edges=total_components-1;
    int max_edges=min((int)cnt0.size(),(int)cnt1.size());

    return (needed_edges<=max_edges);
}

void solve()
{
    cin>>n>>m; int max_=-1;
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<int> candidates;
    for(int i=1;i<=n;i++) {
        candidates.push_back(a[i]);
    }
    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()),candidates.end());

    for(int i=1;i<=m;i++)
    {
        int u,v; cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int l=0,r=candidates.size()-1;int ans=-1;
    
    while(l<=r)
    {
        int mid =(l+r)>> 1;
        int threshold=candidates[mid];
        
        if(check(threshold))
        {
            ans=threshold;
            r=mid-1;
        }
        else l=mid+1;
    }
    
    cout<<ans<<endl;
}


signed main()
{
    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}
