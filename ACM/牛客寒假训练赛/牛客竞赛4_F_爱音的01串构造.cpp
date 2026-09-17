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


int main()
{
    untie();

    int t;cin>>t;
    while(t--)
    {
        int a,b;cin>>a>>b;
        string ans;

        if(a>=b)
        {
            int group=b+1;
            int min_len=a/group;
            int extra=a%group;

            vector<int> zeros(group,min_len);
            for(int i=0;i<extra;i++) zeros[i]++;

            for(int i=0;i<group;i++)
            {
                ans+=string(zeros[i],'0');
                if(i<b) ans+='1';
            }
        }

        else
        {
            int group=a+1;
            int min_len=b/group;
            int extra=b%group;

            vector<int> ones(group,min_len);
            for(int i=0;i<extra;i++) ones[i]++;

            for(int i=0;i<group;i++)
            {
                ans+=string(ones[i],'1');
                if(i<a)
                ans+='0';
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}