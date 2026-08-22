#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define int ll
const int N= 15000+10;
const int MOD=1e9+7;

vector<int> edges[N];
vector<bool> vis_(N,false);

bool query(int a,int b)
{
    cout<<"? "<<a<<" "<<b<<endl;
    int winner; cin>>winner;
    return winner==a;
}


void solve()
{
    int n,k; cin>>n>>k;
    queue<int> q;
    vector<int> ans;
    for(int i=1;i<=n;i++) q.push(i);

    while(q.size()>1)
    {
        auto a=q.front(); q.pop();
        auto b=q.front(); q.pop();

        if(query(a,b))
        {
            q.push(a);
            edges[a].push_back(b);
        }
        else
        {
            q.push(b);
            edges[b].push_back(a);
        }
    }
    
    auto first=q.front(); ans.push_back(first);
    vis_[first]=true;

    while(ans.size()<k)
    {
        queue<int> q2;
        for(auto& v : edges[first])
        {
            if(vis_[v]) continue;
            q2.push(v);
        }
        
        while(q2.size()>1)
        {
            auto a=q2.front(); q2.pop();
            auto b=q2.front(); q2.pop();

            if(query(a,b))
            {
                q2.push(a);
                edges[a].push_back(b);
            }
            else
            {
                q2.push(b);
                edges[b].push_back(a);
            }
        }

        auto v=q2.front(); ans.push_back(v);
        vis_[v]=true;
        first=v;
    }

    cout<<"!";
    for(auto& a : ans) cout<<" "<<a;
    cout<<endl;
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