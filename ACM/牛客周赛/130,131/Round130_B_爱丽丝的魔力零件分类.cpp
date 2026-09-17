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

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

int main()
{
    untie();

    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        
        char text[n][n];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>text[i][j];
     
        bool find=false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {               
                    if(text[i][j]=='*')
                    {
                        if((text[i-1][j]=='*'&&text[i+1][j]=='*'&&(text[i][j-1]=='*'||text[i][j+1]=='*'))&&(i-1>=0&&i+1<n&&(j-1>=0||j+1<n)))
                        {
                            find=true;
                            break;
                        }
                        else if((text[i][j-1]=='*'&&text[i][j+1]=='*'&&(text[i+1][j]=='*'||text[i-1][j]=='*'))&&(j-1>=0&&j+1<n&&(i-1>=0||i+1<n)))
                        {
                            find=true;
                            break;
                        }
                    }
            }
        }

        if(find) cout<<"T"<<endl;
        else cout<<"L"<<endl;
        
    }

    return 0;
}