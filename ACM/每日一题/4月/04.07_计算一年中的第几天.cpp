#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=1e5+10;
const int mod=1e9+7;
const int MOD=998244353;
const int P=13331;
const int INF=0x3f3f3f3f;
const double EPS=1e-6;
ll f[N+10];//阶乘
ll inv_f[N+10];//逆元
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
priority_queue<int,vector<int>,greater<int>> heap_small;//小跟堆
priority_queue<int,vector<int>,less<int>> heap_big;//大跟堆

ll qpow(ll a,ll b,ll c)//(a^b) mod c
{ 
    ll ans =1;
    a%=c;
    while(b)
    {
        if(b&1) ans=(ans*a)%c;
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
void init()
{
    f[0]=1;
    for(int i=1;i<N;i++)
    {
        f[i]=f[i-1]*i%MOD;
    }

    //求逆元
    inv_f[N-1]=qpow(f[N-1],MOD-2,MOD)%MOD;
    for(int i=N-2;i>=0;i--)
    {
        inv_f[i]=inv_f[i+1]*(i+1)%MOD;
    }
}
ll C(int n,int k)
{
    if(k<0||k>n) return 0;

    return f[n]%MOD*inv_f[k]%MOD*inv_f[n-k]%MOD;
}


int main()
{
while(1)
{
    int year,month,day,t,s;
if(!(cin >>year>>month>>day)) return 0;
if((year%4==0&&year%100!=0)||year%400==0){
    t=29;
}
else{
    t=28;
}
switch (month){
    case 1:s=0;
    break;
    case 2:s=31;
    break;
    case 3:s=31+t;
    break;
    case 4:s=31+t+31;
    break;
    case 5:s=31+t+31+30;
    break;
    case 6:s=31+t+31+30+31;
    break;
    case 7:s=31+t+31+30+31+30;
    break;
    case 8:s=31+t+31+30+31+30+31;
    break;
    case 9:s=31+t+31+30+31+30+31+31;
    break;
    case 10:s=31+t+31+30+31+30+31+31+30;
    break;
    case 11:s=31+t+31+30+31+30+31+31+30+31;
    break;
    case 12:s=31+t+31+30+31+30+31+31+30+31+30;
    break;
}
s=s+day;
printf("%d\n",s);
}





return 0;
}

