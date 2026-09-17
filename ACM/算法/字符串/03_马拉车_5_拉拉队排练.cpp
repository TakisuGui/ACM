#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e6+10;
const int MOD=19930726;

ll qpow(ll a,ll b,ll c=MOD)//(a^b) mod c
{ 
    ll ans=1;
    a%=c;
    while(b)
    {
        if(b&1) ans=(ans*a)%c;
        a=a*a%c;
        b>>=1;
    }
    return ans;
}

string get_ss(string s,int n)
{
    string ss; ss.resize(2*n+1);

    for(int i=0,j=0;i<2*n+1;i++)
    {
        if(i%2==0) ss[i]='#';
        else ss[i]=s[j++];
    }
    return ss;
}

int max_len=-1;

vector<int> get_p(string s,int n)
{
    vector<int> p(n);

    for(int i=0,r=0,c=0,len;i<n;i++)
    {
        len=1;
        if(r>i) len=min(r-i,p[2*c-i]);
        while(i+len<n&&i-len>=0&&s[i-len]==s[i+len]) len++;

        if(i+len>r) r=i+len,c=i;
        p[i]=len;
        max_len=max(max_len,len);
    }
    return p;
}


void solve()
{
    int n,k; cin>>n>>k;
    string s; cin>>s;
    string ss=get_ss(s,n);
    int t=2*n+1;

    vector<int> p=get_p(ss,t);

    int sum=0,ans=1;
    vector<int> cnt(N,0);
    for(int i=1;i<t;i+=2) cnt[p[i]-1]++;

    for(int len = (max_len%2==0) ? max_len-1 : max_len ;len>=1&&k>=0;len-=2)
    {
        sum+=cnt[len];
        ans=(ans*qpow(len%MOD,min(sum,k)))%MOD;
        k-=sum;
    }

    if(k>=0) cout<<-1<<endl;
    else cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}