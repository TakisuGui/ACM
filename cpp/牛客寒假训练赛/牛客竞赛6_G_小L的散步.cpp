#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e5+10;
const int MOD=998244353;
const int P=13331;

priority_queue<int,vector<int>,greater<int>> heap_small;//小跟堆
priority_queue<int,vector<int>,less<int>> heap_big;//大跟堆

ll qpow(ll a,ll b,ll c)//(a^b) mod c
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

ll n,m,l;

int main()
{
    untie();
    cin>>n>>m>>l;

    vector<ll> x(n),y(m);
    for(int i=0;i<n;i++) cin>>x[i];
    for(int i=0;i<m;i++) cin>>y[i];

    vector<ll> gap;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=x[i];
        gap.push_back(sum);
    }

    sort(gap.begin(), gap.end());

    vector<ll>pos(m+1,0);
    for(int i=1;i<=m;i++) pos[i]=pos[i-1]+y[i-1];

    for(int t=0;t<=m;t++)
    {
        ll back=pos[t],front=back+l;

        ll left=0,right=gap.size()-1,idx=gap.size();

        while(left<=right)
        {
            ll mid=(left+right)/2;
            if(gap[mid]>back)
            {
                idx=mid;
                right=mid-1;
            }
            else left=mid+1;
        }

        if(idx<gap.size()&&gap[idx]<front)
        {
            cout<<"YES\n";
            return 0;
        }
    }

    cout<<"NO"<<endl;

    return 0;
}