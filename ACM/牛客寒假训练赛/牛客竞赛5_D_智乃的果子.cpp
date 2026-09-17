#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;
const ll MOD=1e9+7;
const int P=13331;

priority_queue<int,vector<int>,greater<int>> heap_small;
priority_queue<int,vector<int>,less<int>> heap_big;

ll qpow(ll a,ll b,ll c)
{ 
    ll ans =1;
    a%=c;
    while(b)
    {
        if(b&1) ans=(ans*a) %c;
        a=a*a%c;
        b>>=1;
    }
    return ans;
}

ll gcd(ll a,ll b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}

ll floor_log2(ll x)
{
    if(x<=1) return 0;
    else return 63-__builtin_clzll(x);
}

void untie()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int count_1(ll x)
{
    return __builtin_popcountll(x);
}


int main()
{
    untie();

    int n;cin>>n;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;

    for(int i=1;i<=n;i++)
    {
        ll c,w;cin>>c>>w;
        pq.push({w,c});
    }

    ll ans=0;

    while(!pq.empty())
    {
        auto top_w1=pq.top().first;
        auto top_c1=pq.top().second;
        pq.pop();

        if(pq.empty()&&top_c1==1) break;

        if(top_c1>=2)
        {
            ll pairs=top_c1/2;
            ll new_w=top_w1*2;
            ll cost=(new_w%MOD)*(pairs%MOD)%MOD;
            ans=(ans+cost)%MOD;
            pq.push({new_w,pairs});
            top_c1%=2;
        }

        if(top_c1==1)
        {
            if(pq.empty()) break;
            
            auto top_w2=pq.top().first;
            auto top_c2=pq.top().second;
            pq.pop();
            
            ll new_w=top_w1+top_w2;
            ans=(ans+(new_w%MOD))%MOD;
            pq.push({new_w,1});
            
            if(top_c2>1)
            {
                pq.push({top_w2,top_c2-1});
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}