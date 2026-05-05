#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void slove()
{
    int n; cin>>n;
    vector<pair<ll,ll>> choco(n);
    for (int i=0;i<n;i++) cin>>choco[i].first>>choco[i].second;

    sort(choco.begin(),choco.end());

    priority_queue<ll, vector<ll>,greater<ll>> pq;
    ll t=0; int idx=0;
    while(idx<n||!pq.empty())
    {
        while(idx<n&&choco[idx].first<=t)
        {
            pq.push({choco[idx].second});
            idx++;
        }
        if(pq.empty())
        {
            t=choco[idx].first;
            continue;
        }

        ll d=pq.top(); pq.pop();
        t+=d;
    }

    cout<<t<<"\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--)
    {
        slove();
    }

    return 0;
}