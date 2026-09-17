#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll MOD=998244353;


ll qpow(ll a,ll b,ll p)
{
    ll ans=1;
    a%=p;
    while(b)
    {
        if(b&1) ans=(ans*a)%p;
        a=a*a%p;
        b=b>>1;
    }
    return ans;
}

void slove()
{
    ll n,m,k; cin>>n>>m>>k;
    unordered_map<ll,ll> row,line;
    vector<pair<ll,ll>>dex(k);

    for(int i=0;i<k;i++)
    {
        int x,y; cin>>x>>y;
        dex[i].first=x,dex[i].second=y;
        row[x]++; line[y]++;
    }

    ll S=(n-row.size())*(m-line.size());
    ll cnt=0;

    cnt+=(S%MOD)*qpow(2,((m*n)-m-n+1-k)%(MOD-1)+(MOD-1),MOD)%MOD;

    for(auto point:dex)
    {
        if(row[point.first]==1&&line[point.second]==1)
        {
            cnt+=qpow(2,((m*n)-m-n+1-(k-1))%(MOD-1)+(MOD-1),MOD)%MOD;
            cnt%=MOD;
        }
    }

    cout<<cnt%MOD<<endl;
}

int main()
{
    int t; cin>>t;
    while(t--)
    {
        slove();
    }

    return 0;
}