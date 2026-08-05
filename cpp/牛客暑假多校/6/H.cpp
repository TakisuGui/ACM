#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=2e5+10;
const int MOD=1e7+7;

vector<bool> prime(N,true);

void sieve_of_eratosthenes()
{
    prime[0]=prime[1]=false;

    for(int p=2;p*p<=N;p++)
    {
        if(prime[p])
        {
            for(int j=p*p;j<N;j+=p) prime[j]=false;
        }
    }
}

void solve()
{
    int n; cin>>n;

    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    else if(n==2)
    {
        cout<<1<<" "<<2<<endl;
        return;
    }
    else if(n==3||n==4||n==6)
    {
        cout<<-1<<endl;
        return;
    }
    
    if(!prime[n-1])
    {
        for(int i=1;i<=n;i++) cout<<i<<" ";
        cout<<endl;
    }
    else
    {
        for(int i=1;i<=n-4;i++) cout<<i<<" ";
        for(int i=n;i>=n-3;i--) cout<<i<<" ";
        cout<<endl;
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve_of_eratosthenes();
    ll t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}