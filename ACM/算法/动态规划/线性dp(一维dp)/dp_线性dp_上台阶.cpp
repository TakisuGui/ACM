#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
typedef long long ll;
const int MOD = 100003;

int n,k;
ll dp[N];
ll pre[N];

int main()
{
    cin>>n>>k;
    dp[0]=1;
    pre[0]=1;

    for(int i=1;i<=n;i++)
    {
        int left=max(0, i-k);

        if(left==0) dp[i]=pre[i-1]%MOD;
        else dp[i]=(pre[i-1]-pre[left-1]+MOD)%MOD;

        pre[i]=(pre[i-1]+dp[i])%MOD;
    }

    cout<<dp[n]<<endl;

    return 0;
}


