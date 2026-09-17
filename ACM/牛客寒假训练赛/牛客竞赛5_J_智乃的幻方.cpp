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

int a[4][4];
int tp[10];

int main()
{
    untie();

    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin>>a[i][j];
            tp[a[i][j]]++;
        }
    }

    bool find=true;

    for(int i=1;i<=9;i++)
    {
        if(tp[i]==1) continue;
        else
        {
            find=false;
            break;
        }
    }


    if(a[1][1]+a[1][2]+a[1][3]==a[2][1]+a[2][2]+a[2][3]&&a[2][1]+a[2][2]+a[2][3]==a[3][1]+a[3][2]+a[3][3])
    {
        
    }
    else find=false;

    if(a[1][1]+a[2][1]+a[3][1]==a[1][2]+a[2][2]+a[3][2]&&a[1][2]+a[2][2]+a[3][2]==a[1][3]+a[2][3]+a[3][3]&&a[1][2]+a[2][2]+a[3][2]==a[3][1]+a[3][2]+a[3][3])
    {

    }
    else find=false;

    if(a[1][1]+a[2][2]+a[3][3]==a[3][1]+a[2][2]+a[1][3]&&a[1][1]+a[2][2]+a[3][3]==a[3][1]+a[3][2]+a[3][3])
    {

    }
    else find=false;

    if(find) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    

    return 0;
}