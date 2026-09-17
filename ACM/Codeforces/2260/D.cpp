#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
const int N=1e5+10;
const int MOD=998244353;

struct Interval 
{
    int l,r;
};

bool check(int n,const string& s,int K)
{
    vector<Interval> current={{0,0}};
    for(int i=0;i<n;i++) 
    {
        vector<Interval> next_candidates;
        for(const auto& inv : current) 
        {
            if(inv.l<inv.r) 
            {
                next_candidates.push_back({inv.l-K,inv.r+K});
            } 
            else 
            {
                int x=inv.l;
                next_candidates.push_back({x-K,x-1});
                next_candidates.push_back({x+1,x+K});
            }
        }
        vector<Interval> filtered;
        for(const auto& inv : next_candidates)
        {
            int cl=inv.l,cr=inv.r;
            if(s[i]=='+') cl=max(cl,1);
            else if(s[i]=='-') cr=min(cr,-1);
            else if(s[i]=='0')
            {
                cl=max(cl,0);
                cr=min(cr,0);
            }
            if(cl<=cr) filtered.push_back({cl,cr});
        }
        if(filtered.empty()) return false;
        sort(filtered.begin(),filtered.end(),[](const Interval& a,const Interval& b)
        {
            return a.l<b.l;
        });
        vector<Interval> merged;
        for(const auto& inv : filtered)
        {
            if(merged.empty()) merged.push_back(inv);
            else 
            {
                if(inv.l<=merged.back().r+1) merged.back().r=max(merged.back().r,inv.r);
                else merged.push_back(inv);
            }
        }
        current=merged;
    }
    return true;
}

void solve() 
{
    int n; cin>>n;
    string s; cin>>s;
    if(s[0]=='0') 
    {
        cout<<-1<<"\n";
        return;
    }
    for(int i=0;i<n-1;i++) 
    {
        if(s[i]=='0'&&s[i+1]=='0') 
        {
            cout<<-1<<"\n";
            return;
        }
    }
    int low=1,high=2*n,ans=-1;
    while(low<=high) 
    {
        int mid=low+(high-low)/2;
        if(check(n,s,mid))
        {
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    cout<<ans<<"\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll qrTNum; cin>>qrTNum;
    while(qrTNum--) solve();
    return 0;
}