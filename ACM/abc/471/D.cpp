#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
 {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int Q; ll V; cin>>Q>>V;
    
    priority_queue<pair<ll, ll>> pq;
    ll cur_time=0;
    
    for (int i=0; i<Q;i++)
    {
        int type;
        cin >> type;
        
        if(type==1) 
        {
            ll t,w; cin>>t>>w;
            cur_time=t;
            pq.push({w-t,t});
        } 
        else 
        {
            ll t; cin>>t;
            cur_time=t;
            
            if(pq.empty()) cout<<-1<<"\n";
            else 
            {
                auto [adj, insert_t] = pq.top();
                pq.pop();
                ll actual=min(V, adj + t);
                cout<<actual<<"\n";
            }
        }
    }
    
    return 0;
}