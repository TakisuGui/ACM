#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull=unsigned long long;
#define endl "\n"
#define int ll
const int N=1e6+10;
const int MOD=998244353;

vector<int> primes;

vector<int> sieve_of_eratosthenes(int n)
{
    if(n<2) return {};

    vector<bool> prime(n+1,true);
    prime[0]=prime[1]=false;

    for(int p=2;p*p<=n;p++)
    {
        if(prime[p])
        {
            for(int j=p*p;j<=n;j+=p) prime[j]=false;
        }
    }

    vector<int> primes;
    for (int i=2; i<=n;i++)
    if (prime[i]) primes.push_back(i); 
    
    return primes;
}

void solve()
{
    int n; cin>>n;
    int ans=0;
    for(int i=0;i<primes.size();i++)
    {
        int k=primes[i];
        if(k*k*k>n) break;
        while(n%(k*k*k)==0)
        {
            n/=(k*k*k);
            ans++;
        }
    }
    cout<<ans<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    primes=sieve_of_eratosthenes(N);
    ll t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}