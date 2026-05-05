#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=1e6+10;

vector<int> a;
vector<bool> prime(N+1,true);

void ini()
{
    prime[1]=false,prime[2]=true;

    for(ll i=2;i<=N;i++)
    {
        if(prime[i])
        {
            for(ll j=i*i;j<=N;j+=i) prime[j]=false;
        }
    }

    for(int i=2;i<=N;i++)  if(prime[i]) a.push_back(i);
}

void solve()
{

    ll n; cin>>n;

    if(n==1)
    {
        cout<<"No"<<endl;
        return;
    }

    bool pass=true;
    for(auto v:a)
    {
        if(v*v>n) break;
        
        if(n%v==0)
        {
            pass=false;
            break;
        }
    }

    cout<<(pass ? "Yes" : "No")<<endl;
}


int main()
{
    ini();
    solve();

    return 0;
}