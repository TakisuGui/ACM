#include<bits/stdc++.h>
using namespace std;

const int MOD=998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];

        vector<int> dp(n+1,0);
        dp[0]=1;

        vector<int> pre(n+3,0);
        pre[0]=1;

        int left=1; int mask=0;

        for(int i=1;i<=n;i++)
        {
            while((mask&a[i])!=0)
            {
                left++;
                mask=0;
                for(int k=left;k<i;k++) mask|=a[k];
            }

            mask|=a[i];

            long long sum;
            if(left>=2) sum=(pre[i-1]-pre[left-2]+MOD)%MOD;
            else sum=pre[i-1]%MOD;

            dp[i]=sum;
            pre[i]=(pre[i-1]+dp[i])%MOD;
        }

        cout<<dp[n]<<endl;
    }

    return 0;
}