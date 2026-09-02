#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e6+10;

map<int,int> mp;
ll ans=0;

void push(ll row,ll cur)
{
    ll h=cur-row;
    for(auto it=++mp.begin();it!=--mp.end();)
    {
        auto &[l,r]=*it;
        if(r-l>=h)
        {
            ans+=(r-l+1+r-l-h+2)*h/2;
            mp[l]-=h;
            it++;
        }
        else
        {
            ans+=(r-l+2)*(r-l+1)/2;
            it=mp.erase(it);
        }
    }
}

void solve()
{
    int n,k; cin>>n>>k;
    vector<pair<int,int>> pos;
    for(int i=1;i<=k;i++)
    {
        int x; cin>>x;
        int l=1,r=n,row=1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if((mid-1)*mid/2<x) //判断第mid层之前的总数是否小于x
            {
                row=mid;
                l=mid+1;
            }
            else r=mid-1;
        }

        int col=x-((row-1)*row/2);
        pos.push_back({row,col});
    }

    sort(pos.begin(),pos.end(),[](const auto & a,const auto &b)
    {
        if(a.first==b.first) return a.second<b.second;
        else return a.first>b.first;
    });

    mp.clear();
    mp[-1]=-1,mp[n+2]=n+2;
    ll cur=pos[0].first;
    mp[pos[0].second]=pos[0].second;
    ans=0;

    for(auto [x,y] :pos)
    {
        if(cur>x) push(x,cur);
        cur=x;

        auto p=mp.upper_bound(y),q=prev(p);
        if(y<=q->second) continue;
        if(y==p->first-1&&y==q->second+1)
        {
            q->second=p->second;
            mp.erase(p);
        }
        else if(y==q->second+1) q->second+=1;
        else if(y==p->first-1)
        {
            mp.insert({y,p->second});
            mp.erase(p);
        }
        else mp.insert({y,y});
    }

    push(0,cur);
    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}