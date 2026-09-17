#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=5e5+10;

vector<bool> prime(N,true);

void ini()
{
    prime[0]=false; prime[1]=false;
    for(int i=2;i*i<=N;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<=N;j+=i) prime[j]=false;
        }
    }
}

void solve()
{
    int n; cin>>n;
    int cnt=0;
    if(n>=2) cnt++;

    for(int i=3;i<=n;i+=2)
    {
        if(!prime[i]) continue;
        int j=i*i-2;
        if(j>n) break;

        if(prime[j]) cnt+=2;
    }

    cout<<cnt<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    ini();
    while(t--)
    {
        solve();
    }

    return 0;
}