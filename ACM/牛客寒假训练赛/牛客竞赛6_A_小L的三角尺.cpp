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

int n,w;;

int main()
{
    untie();
    cin>>n>>w;

    vector<double> x(n),y(n),used(n,0);
    vector<double> cur(n);

    double total=0;
    priority_queue<pair<double, int>> pq;

    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
        cur[i]=sqrt((double)x[i]*x[i]+(double)y[i]*y[i]);
        total+=cur[i];

        if(y[i]>=1)
        {
            double can_fix=sqrt((double)x[i]*x[i]+(double)(y[i]-1)*(y[i]-1));
            double delta=cur[i]-can_fix;
            pq.push({delta,i});
        }
    }

    double has_used=0;
    while(has_used<w&&!pq.empty())
    {
        auto[delta,i]=pq.top();
        pq.pop();

        if(delta<=1e-12) break;

        used[i]++;
        total-=delta;
        has_used++;

        cur[i]=sqrt((double)x[i]*x[i]+(double)(y[i]-used[i])*(y[i]-used[i]));
        if(used[i]<y[i])
        {
            double next_can_fix=sqrt((double)x[i]*x[i]+(double)(y[i]-used[i]-1)*(y[i]-used[i]-1));
            double new_delta=cur[i]-next_can_fix;
            if(new_delta>1e-12) pq.push({new_delta,i});
        }
    }

    printf("%.10lf\n",total);

    return 0;
}