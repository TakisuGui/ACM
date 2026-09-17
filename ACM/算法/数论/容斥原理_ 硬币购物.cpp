#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define int ll
const int N=1e5+10;
const int MOD=1e9+7;

vector<int> dp(N);
vector<int> value(4);
vector<int> cnt(4);



void solve()
{
    int n; cin>>value[0]>>value[1]>>value[2]>>value[3]>>n;

    dp[0]=1;
    for(int i=0;i<=3;i++)
    {
        for(int j=value[i];j<=100000;j++)
        {
            dp[j]+=dp[j-value[i]];
        }
    }

    while(n--)
    {
        for(int i=0;i<4;i++) cin>>cnt[i];
        int s; cin>>s;


        int ilegal=0;
        // status -> 0001到1111
        for(int status=1;status<=15;status++)
        {
            int t=s;
            int sign=-1; // 奇正偶负
            for(int j=0;j<4;j++)
            {
                if(((status>>j)&1)==1)
                {
                    t-=value[j]*(cnt[j]+1);
                    sign=-sign;
                }
            }

            if(t>=0) ilegal+=dp[t]*sign;
        }

        cout<<dp[s]-ilegal<<endl;
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; t=1;
    while(t--)
    {
        solve();
    }

    return 0;
}