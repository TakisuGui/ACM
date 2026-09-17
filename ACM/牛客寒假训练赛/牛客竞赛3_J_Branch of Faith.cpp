#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll floor_log2(ll x)
{
    if(x<=1) return 0;
    else return 63-__builtin_clzll(x);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;cin>>t;


    while(t--)
    {
        ll n;int q;
        cin>>n>>q;
        
        while(q--)
        {
            ll x;
            cin>>x;
            
            ll d=floor_log2(x);
            
            ll start_num=1ll<<d;
            ll end_num=(1LL<<(d+1))-1;
            
            ll act_end=min(end_num,n);
            
            cout<<act_end-start_num+1<<endl;
        }
    }
    return 0;
    
}