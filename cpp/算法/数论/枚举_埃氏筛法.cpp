#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e8+10;
int f[N];

vector<int>sieve_of_eratosthenes(int n)
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

int main()
{
    int n; cin>>n;
    vector<int> primes=sieve_of_eratosthenes(n);

    for(int p:primes) cout<<p<<endl;

    return 0;
}