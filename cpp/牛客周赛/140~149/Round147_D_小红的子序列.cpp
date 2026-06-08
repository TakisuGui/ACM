#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
const int N=2e5+10;
const int MX=1e6+10;

int dp[MX]; 
int id[MX];
int f[N];
int pre[N];
int min_prime[MX];
vector<int> a(N);

void ini(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(min_prime[i]==0)
        {
            for(int j=i;j<n;j+=i) if(min_prime[j]==0) min_prime[j]=i;
        }
    }
}


void solve()
{   
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    int max_len=0;
    int best_idx=0;
    
    for(int i=1;i<=n;i++)
    {
        int v=a[i];
        f[i]=1;
        pre[i]=0;

        int temp=v;
        while(temp>1)
        {
            int p=min_prime[temp];
            int pre_v=v/p;

            if(dp[pre_v]>0)
            {
                if(dp[pre_v]+1>f[i])
                {
                    f[i]=dp[pre_v]+1;
                    pre[i]=id[pre_v];
                }
            }

            while (temp%p==0) temp/=p; // 跳过相同的质因子
        }

        if(f[i]>dp[v])
        {
            dp[v]=f[i];
            id[v]=i;
        }

        if(dp[v]>max_len)
        {
            max_len=f[i];
            best_idx=i;
        }
    }

    cout<<max_len<<endl;
    vector<int> ans;
    int curr=best_idx;
    while(curr!=0)
    {
        ans.push_back(a[curr]);
        curr=pre[curr];
    }
    for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" ";
    cout<<endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        ini(MX);
        solve();
    }

    return 0;
}