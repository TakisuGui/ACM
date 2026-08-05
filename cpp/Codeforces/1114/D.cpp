#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e7+7;


void solve()
{
    int n; cin>>n;
    map<ll, int> cnt;
    vector<int> b(n);
    for(int i=0;i<n;i++) 
    {
        cin>>b[i];
        cnt[b[i]]++;
    }

    vector<pair<ll,int>> groups;
    for(auto& [key,value] : cnt)
    {
        groups.push_back({key,value});
    }
    int k=groups.size();

    if(groups[0].first!=0)
    {
        cout<<-1<<endl;
        return;
    }

    vector<int> x(k);

    if(k==1)
    {
        x[0]=1;
    }
    else
    {
        for(int m=0;m<k-1;m++)
        {
            int diff=groups[m+1].first-groups[m].first;
            int c=groups[m].second;

            if(diff%c!=0)
            {
                cout<<-1<<endl;
                return;
            }
            x[m]=diff/c;
        }

        if(x[0]<1)
        {
            cout<<-1<<endl;
            return;
        }
        for(int m=1;m<k-1;m++)
        {
            if(x[m]<=x[m-1])
            {
                cout<<-1<<endl;
                return;
            }
        }

        x[k-1]=x[k-2]+1;
    }

    map<ll,ll> mp;
    for(int m=0;m<k;m++)
    {
        mp[groups[m].first]=x[m];
    }

    for(int i=0;i<n;i++)
    {
        cout<<mp[b[i]]<<" ";
    }
    cout<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}