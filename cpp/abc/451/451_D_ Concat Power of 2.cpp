#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    vector<string> power;
    for(ll i=0;i<31;i++)
    {
        ll val=(1ll<<i);
        if(val>1000000000ll) break;
        power.push_back(to_string(val));
    }

    set<ll> results;
    queue<string> q;

    for(const string & p:power)
    {
        ll val=stoll(p);
        if(val<=1000000000ll)
        {
            results.insert(val);
            q.push(p);
        }
    }

    while(!q.empty())
    {
        string curr=q.front(); q.pop();

        for(const string& p:power)
        {
            string next_s=curr+p;

            if(next_s.length()>10) continue;
            ll next_val=stoll(next_s);
            if(next_val<=1000000000ll)
            {
                if(results.find(next_val)==results.end())
                {
                    results.insert(next_val);
                    q.push(next_s);
                }
            }
        }
    }

    auto it=results.begin();
    advance(it,n-1);
    cout<<*it<<endl;

    return 0;
}